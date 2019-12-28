#include "SequenceTable.h"

int main()
{
    SequenceList SL = Init(); //初始化

    //插入测试
    for (int i = 1; i <= MAX_TABLE_SIZE; i++)
    {
        Insert(SL, i);
    }
    //插入报错
    Insert(SL, 999);

    //查找测试
    cout << Search(SL, 125) << endl;

    //删除测试
    Remove(SL);
    int size = SL.Top;
    Remove(SL, 0); //删除报错
    for (int i = 1; i < size/2; i++)
    {
        Remove(SL, i);
    }

    return 0;
}