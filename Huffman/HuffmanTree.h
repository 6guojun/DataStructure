#pragma once

//通用配置文件
#include "CommonSetting.h"

//权值表
typedef struct
{
    int Weight[ByteSize];    //权重表
    char Position[ByteSize]; //序号表
    int num;                 //数目
} WeightTable;

//霍夫曼节点结构体
typedef struct
{
    int weight;     //权值大小
    int parent;     //双亲下标
    int leftChild;  //左孩子下标
    int rightChild; //右孩子下标
} HuffmanElement;

//哈夫曼树结构体
typedef struct
{
    HuffmanElement Elem[MAXSIZE]; //霍夫曼树（双亲-孩子表示法）
    int num;                      //叶子节点数目
    int root;                     //根位置
} HuffmanTree;

WeightTable InitWeightTable();
WeightTable ReadFileWeight(string);
HuffmanTree CreatHuffmanTree(WeightTable);
void FindMin(HuffmanTree, int[]);
void SaveHuffmanTree(char[], HuffmanTree);

//初始化权值表
WeightTable InitWeightTable()
{
    //定义表
    WeightTable WT;
    //设置表为空
    for (int i = 0; i < ByteSize; i++)
    {
        WT.Weight[i] = WT.Position[i] = 0;
    }
    //设置表数目
    WT.num = 0;

    return WT;
}

//读取权重
WeightTable ReadFileWeight(string filename)
{
    //初始化权值表
    WeightTable WT = InitWeightTable();

    //打开文件
    ifstream ifs;
    ifs.open(filename, ios::in);

    //逻辑检查
    if (!ifs.is_open())
    {
        cout << "文件打开失败！" << endl; //报错
        system("pause");                  //暂停
        exit(0);                          //退出
    }

    //读取字符
    char c;
    while(ifs.get(c))
    {
        //如果原来没读取到
        if (WT.Weight[c + 128] == 0)
        {
            //总数目增加
            WT.num++;
        }
        //权值加一
        WT.Weight[c + 128]++;
    }

    //关闭文件
    ifs.close();

    //压缩权值表
    int count = 0, pla = 0;
    while (count != WT.num)
    {
        //不为0则存在，计数增加
        if (WT.Weight[pla++] != 0)
        {
            //前移
            WT.Weight[count] = WT.Weight[pla - 1];
            //标记
            WT.Position[count] = pla - 129;
            count++;
        }
    }

    //返回权值表
    return WT;
}

//获取哈夫曼树中未被访问的最小的两个值的下标
void FindMin(HuffmanTree HT, int Returns[2])
{
    //规定WeightMin1<WeightMin2，num为读取到的权值大小
    int WeightMin1, WeightMin2, num;
    WeightMin1 = WeightMin2 = 0;

    //遍历所有节点
    for (int i = 0; i < HT.num * 2 - 1; i++)
    {
        //如果这个节点已经遍历过
        if (HT.Elem[i].parent != -1)
        {
            //跳过
            continue;
        }

        //获取其权值大小
        num = HT.Elem[i].weight;
        //如果存储权值
        if (WeightMin2 != 0 && WeightMin1 != 0) //WeightMin2为0则WeightMin1一定为0
        {
            //当前权值小于最小的
            if (num < WeightMin1)
            {
                WeightMin2 = WeightMin1; //WeightMin1变为MWeightMin2成为次小的
                Returns[1] = Returns[0]; //返回的下标亦是如此
                WeightMin1 = num;        //WeightMin1赋值为读取到的最小值
                Returns[0] = i;          //返回值的小标亦是如此
            }
            //大于最小的而小于次小的
            else if (num < WeightMin2)
            {
                //更新次小值信息
                WeightMin2 = num;
                Returns[1] = i;
            }
            //继续
            continue;
        }
        //如果最小值为0（即还没读取到）
        if (WeightMin1 == 0)
        {
            WeightMin1 = num;
            Returns[0] = i;
            //继续
            continue;
        }
        //如果次小值为0（即还没读取到）
        if (WeightMin2 == 0)
        {
            WeightMin2 = num;
            Returns[1] = i;
        }
        //未防止一开始读取到的数值次小比最小大
        if (WeightMin2 < WeightMin1)
        {
            //交换
            WeightMin2 += WeightMin1;
            WeightMin1 = WeightMin2 - WeightMin1;
            WeightMin2 -= WeightMin1;
            //交换
            Returns[0] += Returns[1];
            Returns[1] = Returns[0] - Returns[1];
            Returns[0] -= Returns[1];
        }
    }
}

//生成霍夫曼树
HuffmanTree CreatHuffmanTree(WeightTable WT)
{
    int i; //循环控制变量

    HuffmanTree HT;   //声明树
    HT.num = WT.num;  //初始化树的叶子节点数目，等于权值表中的总数目
    HT.root = HT.num; //记录根节点位置，虽然会充当中间变量，但无伤大雅

    //初始化哈夫曼树各个叶子节点（其实应该是森林）
    for (i = 0; i < HT.num; i++)
    {
        /*
        HT.Elem[i] = {WT.Weight[i], -1, -1, -1}; //对于没有指针的结构体可以使用这种初始化方式，但是不太推荐
        */
        HT.Elem[i].weight = WT.Weight[i];                                      //权重赋值
        HT.Elem[i].parent = HT.Elem[i].leftChild = HT.Elem[i].rightChild = -1; //初始化双亲、左右孩子为-1（即没有）
    }

    //到此哈夫曼树初始化成功
    cout << "哈夫曼树\t初始化\t成功" << endl;

    int MinPos[2] = {0};
    while (HT.root < HT.num * 2 - 1)
    {
        //获取两个最小的
        FindMin(HT, MinPos);
        //将二者合并为一棵树
        //HT.Elem[HT.num] = {HT.Elem[MinPos[0]].weight + HT.Elem[MinPos[1]].weight, -1, MinPos[0], MinPos[1]};
        HT.Elem[HT.root].weight = HT.Elem[MinPos[0]].weight + HT.Elem[MinPos[1]].weight; //权值相加
        HT.Elem[HT.root].parent = -1;                                                    //双亲赋值为-1
        HT.Elem[HT.root].leftChild = MinPos[0];                                          //左孩子赋值
        HT.Elem[HT.root].rightChild = MinPos[1];                                         //右孩子赋值
        //设置二者双亲为当前节点
        HT.Elem[MinPos[0]].parent = HT.Elem[MinPos[1]].parent = HT.root++;
    }

    //到此哈夫曼树创建成功
    cout << "哈夫曼树\t创建\t成功" << endl;

    return HT;
}

void SaveHuffmanTree(char FileName[], HuffmanTree HT)
{
    ofstream ofs;
    ofs.open(FileName, ios::trunc);

    //逻辑检查
    if (!ofs.is_open())
    {
        cout << "文件保存失败！" << endl; //报错
        system("pause");                  //暂停
        exit(0);                          //退出
    }

    ofs << HT.num << endl;
    ofs << HT.root << endl;
    for (int i = 0; i < HT.root; i++)
    {
        ofs << i << ' ' << HT.Elem[i].weight << ' ' << HT.Elem[i].parent << ' ' << HT.Elem[i].leftChild << ' ' << HT.Elem[i].rightChild << endl;
    }

    ofs.close();

    return;
}

//读取哈夫曼编码
HuffmanTree ReadHuffmanTree(char FileName[])
{
    ifstream ifs;
    ifs.open(FileName, ios::in);

    //逻辑检查
    if (!ifs.is_open())
    {
        cout << "文件打开失败！" << endl; //报错
        system("pause");                  //暂停
        exit(0);                          //退出
    }

    int i, c;
    HuffmanTree HT;
    ifs >> HT.num >> HT.root;
    while (ifs >> i >> HT.Elem[i].weight >> HT.Elem[i].parent >> HT.Elem[i].leftChild >> HT.Elem[i].rightChild)
    {
    }

    return HT;
}