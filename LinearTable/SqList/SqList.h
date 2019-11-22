#include <iostream>
using namespace std;

//宏定义
#define MAXSIZE 100
#define Status int
#define ElemType int

#define OK 1
#define ERR 0
#define OVERFLOW -1

//定义SqList结构体
typedef struct SqList
{
    int Elem[MAXSIZE]; //数组
    int Length;        //长度
    int ListSize;      //总长度
} SqList;

//ADT函数定义
Status InitList(SqList &L);                   //構造一個空的綫性表L
Status DestoryList(SqList &L);                //銷毀綫性表L（綫性表L已存在）
Status ClearList(SqList &L);                  //將L重置為空表（綫性表L已存在）
bool ListEmpty(SqList L);                     //若L為空表，則返回True，否則返回False（綫性表L已存在）
int ListLength(SqList L);                     //返回L中數據元素個數（綫性表L已存在）
Status GetElem(SqList L, int i, ElemType &e); //用e返回L中第i個數據元素的值（綫性表L已存在，1<=i<=ListLength(L)）
int LocateElem(SqList L, ElemType e,
               bool (*fun)(ElemType a, ElemType b));         //返回L中第一个與e满足Compare的數據元素的位序。若這樣的數據元素不存在，則返回值為0（綫性表L已存在，compare()是數據元素判定函數）
Status PriorElem(SqList L, ElemType cur_e, ElemType &pre_e); //若cur_e是L的數據元素，且不是第一個，則用pre_e返回它的前驅，否則操作失敗，pre_e無定義
Status NextElem(SqList L, ElemType cur_e, ElemType &next_e); //若cur_e是L的數據元素，且不是最後一個，則用next_e返回它的後繼，否則操作失敗，next_e無定義
Status ListInsert(SqList &L, int i, ElemType e);             //在L中第i個元素之前插入新的數據元素e，L的長度加一（綫性表L已存在，1<=i<=ListLength(L)）
Status ListDelete(SqList &L, int i, ElemType &e);            //刪除L的第i數據元素，并用e返回其值，L的長度減一（綫性表L已存在，1<=i<=ListLength(L)）
Status ListTraverse(SqList L, Status (*visit)(ElemType e));  //一次對L的每個元素數據調用函數visit().一旦visit()失敗，則操作失敗。（綫性表L已存在）

//習題（課本）函數實現
void Union(SqList &La, SqList Lb);                //A=A∪B
void MergeList(SqList La, SqList Lb, SqList &Lc); //歸并算法

//實驗課函數實現
Status sortSqlist(SqList &L);                         //将一个无序顺序表L变为非递减有序的有序表
void displaySqlist(SqList L);                         //在显示器上显示一个顺序表：每行10个元素
Status MergeSqlist(SqList La, SqList Lb, SqList &Lc); //已知两个有序的顺序表L1和L2，表中元素值非递减有序，请编程将其合并为一个新的顺序表L3，且L3递增有序；

//一个Compare
bool Equal(ElemType a, ElemType b)
{
    return a == b;
}

//構造一個空的綫性表L
Status InitList(SqList &L)
{
    /**
     * （錯誤）在这里还需要判断是否内存溢出
     * L在此之前已經創建完成
     * 所以不用判斷内存溢出
    */
    L.Length = 0;
    L.ListSize = MAXSIZE;
    return OK;
}

//銷毀綫性表L（綫性表L已存在）
Status DestoryList(SqList &L)
{
    SqList *p = &L;
    //如果p成功分配到空間
    if (p)
    {
        free(p);
        p = NULL;
    }
    else
    {
        return ERR;
    }
    return OK;
}

//將L重置為空表（綫性表L已存在）
Status ClearList(SqList &L)
{
    L.Length = 0;
    return OK;
}

//若L為空表，則返回True，否則返回False（綫性表L已存在）
bool ListEmpty(SqList L)
{
    return L.Length == 0;
}

//返回L中數據元素個數（綫性表L已存在）
int ListLength(SqList L)
{
    return L.Length;
}

//用e返回L中第i個數據元素的值（綫性表L已存在，1<=i<=ListLength(L)）
Status GetElem(SqList L, int i, ElemType &e)
{
    /**
     * 第i個數據元素
     * 而非下標
     * 所以需要加一
    */
    if (i > ListLength(L) || i < 1)
        return ERR;
    e = L.Elem[i - 1];
    return OK;
}

//返回L中第一个與e满足Compare的數據元素的位序。若這樣的數據元素不存在，則返回值為0（綫性表L已存在，compare()是數據元素判定函數）
int LocateElem(SqList L, ElemType e, bool (*compare)(ElemType a, ElemType b))
{
    /**
     * 這裏還是位置順序
     * 所以牢記加一
    */
    for (int i = 0; i < L.Length; i++)
    {
        if (compare(L.Elem[i], e))
        {
            return i + 1;
        }
    }
    return 0;
}

//若cur_e是L的數據元素，且不是第一個，則用pre_e返回它的前驅，否則操作失敗，pre_e無定義
Status PriorElem(SqList L, ElemType cur_e, ElemType &pre_e)
{
    int pla = LocateElem(L, cur_e, Equal);
    if (pla <= 1)
    {
        return ERR;
    }
    pre_e = L.Elem[(pla - 1) - 1];
    return OK;
}

//若cur_e是L的數據元素，且不是最後一個，則用next_e返回它的後繼，否則操作失敗，next_e無定義
Status NextElem(SqList L, ElemType cur_e, ElemType &next_e)
{
    int pla = LocateElem(L, cur_e, Equal);
    if (pla == 0 || pla == L.Length)
    {
        return ERR;
    }
    /**
     * next_e = L.Elem[(pla - 1) + 1];
     * 寫成這樣方便理解
    */
    next_e = L.Elem[pla];
    return OK;
}

//在L中第i個元素之前插入新的數據元素e，L的長度加一（綫性表L已存在，1<=i<=ListLength(L)）
Status ListInsert(SqList &L, int i, ElemType e)
{
    if (i > ListLength(L) + 1 || i < 1 || L.Length == L.ListSize)
        return OVERFLOW;
    for (int j = L.Length; j >= i; j--)
    {
        L.Elem[j] = L.Elem[j - 1];
    }
    L.Elem[i - 1] = e;
    L.Length++;
    return OK;
}

//刪除L的第i數據元素，并用e返回其值，L的長度減一（綫性表L已存在，1<=i<=ListLength(L)）
Status ListDelete(SqList &L, int i, ElemType &e)
{
    if (i > ListLength(L) || i < 1)
        return OVERFLOW;

    e = L.Elem[i - 1];
    for (int j = i - 1; j < L.Length; j++)
    {
        L.Elem[j] = L.Elem[j + 1];
    }
    L.Length--;
    return OK;
}

//遍历visit
Status ListTraverse(SqList L, Status (*visit)(ElemType e))
{
    for (int i = 0; i < L.Length; i++)
    {
        if (visit(L.Elem[i]) != OK)
        {
            return ERR;
        }
    }
    return OK;
}

//A=A∪B
void Union(SqList &La, SqList Lb)
{
    //臨時變量
    ElemType e;

    int La_Length = La.Length;
    int Lb_Length = Lb.Length;

    for (int i = 1; i <= Lb_Length; i++)
    {
        GetElem(Lb, i, e); //取Lb中第i個元素數據賦給e
        if (!LocateElem(La, e, Equal))
        {
            ListInsert(La, ++La_Length, e);
        }
    }
}

//歸并算法
void MergeList(SqList La, SqList Lb, SqList &Lc)
{
    InitList(Lc);
    int i = 1, j = 1, k = 0;
    int La_Length = ListLength(La);
    int Lb_Length = ListLength(Lb);
    ElemType ai, bj;
    while ((i <= La_Length && j <= Lb_Length))
    {
        GetElem(La, i, ai);
        GetElem(Lb, j, bj);
        if (ai < bj)
        {
            ListInsert(Lc, ++k, ai);
            i++;
        }
        else
        {
            ListInsert(Lc, ++k, bj);
            j++;
        }
    }
    while (i <= La_Length)
    {
        GetElem(La, i++, ai);
        ListInsert(Lc, ++k, ai);
    }
    while (j <= Lb_Length)
    {
        GetElem(Lb, j++, bj);
        ListInsert(Lc, ++k, bj);
    }
}
//将一个无序顺序表L变为非递减有序的有序表
Status sortSqlist(SqList &L)
{
    //選擇排序
    for (int i = 0; i < L.Length - 1; i++)
    {
        int min = i;
        for (int j = i; j < L.Length; j++)
        {
            if (L.Elem[j] < L.Elem[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            L.Elem[min] += L.Elem[i];
            L.Elem[i] = L.Elem[min] - L.Elem[i];
            L.Elem[min] -= L.Elem[i];
        }
    }
    return OK;
}

//打印SqList
void displaySqlist(SqList L)
{
    cout << "The List :";
    for (int i = 0; i < L.Length; i++)
    {
        cout << L.Elem[i] << "\t";
    }
}
//已知两个有序的顺序表L1和L2，表中元素值非递减有序，请编程将其合并为一个新的顺序表L3，且L3递增有序；
Status MergeSqlist(SqList La, SqList Lb, SqList &Lc)
{
    InitList(Lc);
    int i = 1, j = 1, k = 0;
    int La_Length = ListLength(La);
    int Lb_Length = ListLength(Lb);
    ElemType ai, bj, ck;
    while ((i <= La_Length && j <= Lb_Length))
    {
        if (k != 0)
        {
            GetElem(Lc, k, ck);
            while (ck == ai)
            {
                GetElem(La, ++i, ai);
            }
            while (ck == bj)
            {
                GetElem(Lb, ++j, bj);
            }
        }
        GetElem(La, i, ai);
        GetElem(Lb, j, bj);
        if (ai < bj)
        {
            ListInsert(Lc, ++k, ai);
            i++;
        }
        else
        {
            ListInsert(Lc, ++k, bj);
            j++;
        }
    }
    while (i <= La_Length)
    {
        GetElem(La, i++, ai);
        ListInsert(Lc, ++k, ai);
    }
    while (j <= Lb_Length)
    {
        GetElem(Lb, j++, bj);
        ListInsert(Lc, ++k, bj);
    }
}