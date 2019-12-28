#include <iostream>

using namespace std;

/**
 * 本头文件实现以下功能：
 * 1、初始化一个顺序表
 * 2、向已有表中插入一个元素（表满则拓展）
 * 3、移除表中给定元素（没有元素则返回警告）
 * 4、移除指定下标元素（判断下标是否合法）
 * 5、查找指定元素并返回下标
 * 6、访问指定下标并返回对应元素值
 * 7、返回表中元素个数
 * 8、表中元素排序（从低到高、从高到低）
*/

/**
 * 宏定义
*/
#define MAX_TABLE_SIZE 128 //最大数组长度
typedef int ElemType;      //定义ElemType

/**
 * 结构体定义
*/
typedef struct
{
    /**
     * 表顶 Top 为 0 时，则表示没有任何元素。
     * 因为在进行排序的时候，0位置可以当作哨兵。
    */
    ElemType Element[MAX_TABLE_SIZE + 1]; //元素数组(多出来的一个元素用于存放哨兵)
    int Top;                              //表顶部元素下标
    int TableSize;                        //表长度
} SequenceList;

/**
 * 函数声明
*/
SequenceList Init();                   //初始化顺序表
void Insert(SequenceList &, ElemType); //插入元素
ElemType Remove(SequenceList &, int);  //删除元素（不输入下标则默认表尾）
int Deletee(SequenceList &, ElemType); //删除对应下标元素
ElemType Find(SequenceList, int);      //给下标返回元素
int Search(SequenceList, ElemType);    //查找元素返回下标
int Length(SequenceList);              //长度

/**
 * 函数定义
*/
//初始化顺序表
SequenceList Init()
{
    SequenceList SL;               //定义顺序表
    SL.TableSize = MAX_TABLE_SIZE; //初始化最大容量
    SL.Top == 0;                   //初始化表顶元素为0

    return SL;
}

void Insert(SequenceList &SL, ElemType e)
{
    //合法性检查
    if (SL.Top >= SL.TableSize)
    {
        cout << "你需要插入的顺序表已满，插入失败。" << endl
             << "当前表中元素数目：\t" << SL.Top << endl
             << "表目前最大容纳量：\t" << SL.TableSize << endl;
        return;
    }

    SL.Element[++SL.Top] = e; //插入元素
    return;
}

ElemType Remove(SequenceList &SL, int PLA = -1)
{
    //判断是否有输入删除下标
    if (PLA == -1)
    {
        PLA = SL.Top;
    }
    //合法性判断
    if (PLA <= 0)
    {
        cout << "你需要删除的顺序表已经为空，删除失败。" << endl;
        return SL.Element[0];
    }
    if (PLA > SL.Top)
    {
        cout << "你需要删除的下标超出删除范围，删除失败。" << endl;
        return SL.Element[0];
    }
    //删除
    ElemType del = SL.Element[PLA];
    for (int i = PLA; i < SL.Top; i++)
    {
        SL.Element[i] = SL.Element[i + 1];
    }
    SL.Top--;

    return del;
}

int Delete(SequenceList &SL, ElemType e)
{
    int pla = Search(SL, e); //获得下标
    if (!pla)                //如果查找成功
    {
        Remove(SL, pla); //删除元素
        return pla;
    }
    cout << "未查找到要删除的元素。" << endl;
    return 0;
}

int Search(SequenceList SL, ElemType e)
{
    int i;
    SL.Element[0] = e;
    for (i = SL.Top; SL.Element[i] != e; i--)
        ;
    return i;
}

ElemType Find(SequenceList SL, int i)
{
    //合法性判断
    if (i <= 0)
    {
        cout << "你需要查找的下标小于0，删除失败。" << endl;
        return -1;
    }
    if (i > SL.Top)
    {
        cout << "你需要查找的下标超出查找上线，删除失败。" << endl;
        return -1;
    }

    return SL.Element[i];
}

int Length(SequenceList SL)
{
    return SL.Top;
}