#pragma once

#include "HuffmanTree.h"

//各个数值对应的编码结构体
typedef struct
{
    char Character;
    char Code[10];
} CodePair;

//哈夫曼编码结构体
typedef struct
{
    CodePair Coding[ByteSize];
    int num;
} HuffmanCode;

HuffmanCode CreatHuffmanCode(HuffmanTree, WeightTable);
void Reverse(char *, int);
void SaveHuffmanCode(char FileName[], HuffmanCode HC);
HuffmanCode ReadHuffmanCode(char FileName[]);
void DisplayHuffmanCode(HuffmanCode HC);

//字符串反转
void Reverse(char *s, int n)
{
    for (int i = 0, j = n - 1; i < j; i++, j--)
    {
        char c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

HuffmanCode CreatHuffmanCode(HuffmanTree HT, WeightTable WT)
{
    int i, j;

    HuffmanCode HC;  //声明哈夫曼编码
    HC.num = WT.num; //编码包含个数

    //这边我采用了栈，实际上可以使用字符串的reverse
    stack<int> ReverseCode;
    HuffmanElement HE;
    int pla, count;
    //遍历
    for (i = 0; i < HC.num; i++)
    {
        HC.Coding[i].Character = WT.Position[i]; //输入字符
        HE = HT.Elem[i];                         //临时节点
        pla = i;                                 //读取到的下标
        //如果没到根节点
        while (HE.parent != -1)
        {
            //如果为左孩子
            if (HT.Elem[HE.parent].leftChild == pla)
            {
                //压入0
                ReverseCode.push(0);
            }
            else
            {
                //压入1
                ReverseCode.push(1);
            }
            pla = HE.parent;
            HE = HT.Elem[pla];
        }
        //获取对应字符串
        //HC.Coding[i].Code = new char[ReverseCode.size() + 1]; //开辟字符串空间
        count = ReverseCode.size();                           //遍历长度
        for (j = 0; j < count; j++)
        {
            HC.Coding[i].Code[j] = '0' + ReverseCode.top();
            ReverseCode.pop();
        }
        HC.Coding[i].Code[j] = '\0';
    }

    cout << "哈夫曼树\t编码\t成功" << endl;
    //DisplayHuffmanCode(HC);

    return HC;
}

//打印哈夫曼编码
void DisplayHuffmanCode(HuffmanCode HC)
{
    for (int i = 0; i < HC.num; i++)
    {
        cout << i << '\t' << (int)HC.Coding[i].Character << '\t' << HC.Coding[i].Code << endl;
    }
}

//保存哈夫曼编码
void SaveHuffmanCode(char FileName[], HuffmanCode HC)
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

    for (int i = 0; i < HC.num; i++)
    {
        ofs << i << ' ' << (int)HC.Coding[i].Character << ' ' << HC.Coding[i].Code << endl;
    }

    ofs.close();

    return;
}

//读取哈夫曼编码
HuffmanCode ReadHuffmanCode(char FileName[])
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
    char code[8];
    HuffmanCode HC;
    HC.num = 0;
    while (ifs >> i >> c >> HC.Coding[i].Code)
    {
        HC.Coding[i].Character = c;
        HC.num++;
    }

    ifs.close();

    return HC;
}