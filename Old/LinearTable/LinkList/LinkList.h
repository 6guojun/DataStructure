#pragma once
#include <iostream>

using namespace std;

//定義
typedef int ElemType;
#define Status int
#define OK 1
#define ERR 0
#define OVERFLOW -1

//定義LNode結點
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} * Link, *Position;

//定義鏈表類型
typedef struct
{
    Link head, tail; //分別指向綫性鏈表中的頭節點和最後一個節點
    int Length;      //只是綫性鏈表中元素的個數
} LinkList;

Status MakeNode(Link &p, ElemType e); //分配由p指向的值為e的節點，并返回OK；若分配失敗，則返回ERROR
void FreeNode(Link &p);               //釋放p所指節點

Status InitList(LinkList &L);                   //構造一個空的綫性列表L
Status DestoryList(LinkList &L);                //銷毀綫性鏈表L，L不再存在
Status ClearList(LinkList &L);                  //將綫性鏈表L重置爲空表，并釋放原鏈表的節點空間
Status InsFirst(Link h, Link s);                //已知h指向綫性鏈表的頭節點，將s所指節點插入在第一個結點之前
Status DelFirst(Link h, Link &q);               //已知h指向綫性鏈表的頭節點，刪除鏈表中的第一個節點并以q返回
Status Append(LinkList &L, Link s);             //將指針s所指（彼此以指針相鏈）的一串節點鏈接在綫性表L的最後一個節點之後，并改變鏈表L的尾指針指向新的尾節點
Status Remove(LinkList &L, Link &q);            //刪除綫性表L中的尾節點并以q返回，改變鏈表L的尾指針指向新的尾節點
Status InsBefore(LinkList &L, Link &p, Link s); //已知p只想綫性鏈表L中的一個節點，將s所指節點插入在p所指結點之前,并修改指針p指向新插入的結點
Status InsAfter(LinkList &L, Link &p, Link s);  //已知p只想綫性鏈表L中的一個節點，將s所指節點插入在p所指結點之后,并修改指針p指向新插入的結點
Status SetCurElem(Link &p, ElemType e);         //已知p只想綫性鏈表中的一個節點，用e更新p所指結點中數據元素的值
ElemType GetCurElem(Link p);                    //已知p指向綫性鏈表中的一個結點，返回p所知結點中元素數據的值
Status ListEmpty(LinkList L);                   //若綫性鏈表L為空表，則返回True，否則返回Flase
int ListLength(LinkList L);                     //返回綫性鏈表L中元素個數
Position GetHead(LinkList L);                   //返回綫性鏈表L中頭結點的位置
Position GetLast(LinkList L);                   //返回綫性鏈表L中的最後一個結點的位置
Position PriorPos(LinkList L, Link p);          //已知p只想綫性鏈表L中的一個結點，返回p所知節點的直接前驅的位置
Position NextPos(LinkList L, Link p);           //已知p指向綫性鏈表中的一個結點，返回p所指結點的直接後繼的位置，若無後繼，則返回NULL
Status LocatePos(LinkList L, int i, Link &p);   //返回p只是綫性鏈表L中第i個結點的位置并返回OK，i值不合法時返回ERROR
Position LocateElem(LinkList L, ElemType e,
                    Status (*compare)(ElemType, ElemType)); //返回綫性鏈表L中的第一個與e滿足函數compare()判定關係的元素的位置，若不存在這樣的元素，則返回NULL
Status ListTravaerse(LinkList L, Status (*visit)());        //依次對L的每個元素調用函數visit()。一旦visit()失敗，則操作失敗

//函數定義
//構造一個空的綫性列表L
Status InitList(LinkList &L)
{
    L.head = L.tail = new LNode;
    L.Length = 0;
    return OK;
}

//銷毀綫性鏈表L，L不再存在
Status DestoryList(LinkList &L)
{
    L.head = L.tail = NULL;
    L.Length = 0;
    free(&L);
    //L = NULL;
}

//將綫性鏈表L重置爲空表，并釋放原鏈表的節點空間
Status ClearList(LinkList &L)
{
    L.head = NULL;
    L.Length = 0;
    return OK;
}

//已知h指向綫性鏈表的頭節點，將s所指節點插入在第一個結點之前
Status InsFirst(Link h, Link s)
{
    h->next = s;
    return OK;
}

//已知h指向綫性鏈表的頭節點，刪除鏈表中的第一個節點并以q返回
Status DelFirst(Link h, Link &q)
{
    q = h->next;
    h->next = q->next;
    return OK;
}

//將指針s所指（彼此以指針相鏈）的一串節點鏈接在綫性表L的最後一個節點之後，并改變鏈表L的尾指針指向新的尾節點
Status Append(LinkList &L, Link s)
{
    L.tail->next = s->next;
    L.tail = s;
    return OK;
}

//刪除綫性表L中的尾節點并以q返回，改變鏈表L的尾指針指向新的尾節點
Status Remove(LinkList &L, Link &q)
{

}