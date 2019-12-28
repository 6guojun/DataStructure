#include <iostream>

using namespace std;

/**
 * 宏定义
*/
#define MAX_TABLE_SIZE 128 //最大数组长度
typedef int ElemType;      //定义ElemType

class SQList
{
private:
    ElemType Element[MAX_TABLE_SIZE + 1]; //元素数组(多出来的一个元素用于存放哨兵)
    int Top;                              //表顶部元素下标
    int TableSize;                        //表长度
public:
    SQList();
    void Display();
    ~SQList();
};

SQList::SQList()
{
    TableSize = MAX_TABLE_SIZE; //初始化最大容量
    Top = 0;                   //初始化表顶元素为0
}

void SQList::Display()
{
    for (int i = 1; i <= Top; i++)
    {
        cout << Element[i] << ' ';
    }
    cout << endl;
}

SQList::~SQList()
{
    //delete[] Element; //虽然不知道这么用是否正确
}
