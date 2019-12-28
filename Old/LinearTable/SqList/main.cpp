#include <iostream>
#include "SqList.h"

using namespace std;

int main()
{
    //注释
    cout << "I am from China." << endl;

    SqList L1;    //定义SqList
    InitList(L1); //初始化SqList
    SqList L2;    //定义SqList
    InitList(L2); //初始化SqList
    SqList L3;    //定义SqList
    InitList(L3); //初始化SqList
    {
        L1.Elem[0] = 1;
        L1.Elem[1] = 2;
        L1.Elem[2] = 3;
        L2.Elem[0] = 2;
        L2.Elem[1] = 3;
        L2.Elem[2] = 4;

        L1.Length = L2.Length = 3;
    }
    /**
    Union(L1, L2);
    cout << "The List :";
    for (int i = 0; i < L1.Length; i++)
    {
        cout << L1.Elem[i] << "\t";
    }
    */

    MergeSqlist(L1, L2, L3);
    for (int i = 0; i < L3.Length; i++)
    {
        cout << L3.Elem[i] << "\t";
    }

    /**
    sortSqlist(L1);
    cout << "The List :";
    for (int i = 0; i < L1.Length; i++)
    {
        cout << L1.Elem[i] << "\t";
    }
    */

    //displaySqlist(L1);

    /**
    SqList L;    //定义SqList
    InitList(L); //初始化SqList
    {
        //更新写一个SqList
        L.Elem[0] = 1;
        L.Elem[1] = 2;
        L.Elem[2] = 3;
        L.Elem[3] = 4;
        L.Length = 4;
    }

    //测试获取固定位置元素
    ElemType e;
    GetElem(L, 2, e);
    cout << e << endl;

    cout << "The pla of 3:" << LocateElem(L, 3, Equal) << endl; //获取第一个满足Compare的位序

    //返回前驱
    ElemType pre_e;
    PriorElem(L, 4, pre_e);
    cout << "The pre of 4:" << pre_e << endl;

    //返回后继
    ElemType next_e;
    NextElem(L, 1, next_e);
    cout << "The next of 1:" << next_e << endl;

    //插入元素
    ListInsert(L, 4, 5);
    cout << "The List :";
    for (int i = 0; i < L.Length; i++)
    {
        cout << L.Elem[i];
    }
    cout << endl;

    //删除元素
    ElemType Del_e;
    ListDelete(L, 3, Del_e);
    cout << "The List :";
    for (int i = 0; i < L.Length; i++)
    {
        cout << L.Elem[i];
    }
    cout << endl;
    cout << "Delete:" << Del_e << endl;

    cout << "Is empty：" << ListEmpty(L) << endl; //测试判断是否置空
    ClearList(L);                                 //测试清空列表
    cout << "Is empty：" << ListEmpty(L) << endl; //测试判断是否置空

    DestoryList(L); //测试销毁列表
    */
    return 0;
}