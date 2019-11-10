/**
 * This is about Linklist
 * In this file we show:
 *  1 How to init a linklist
 *  2 How to display it
 *  3 How to sort this linklist
 *  4 How to merge two linklist to one
*/

//import library
#include <iostream>
#include "StatusConfigration.h"

//import namespace
using namespace std;

//Macro definition
typedef int ElemType_1;

//Struction definition
/**
 * Using:
 *  LNode : One node for the linklist it belong to.
 *  LinkList : Always a head of a linklist.
*/
typedef struct LNode
{
    ElemType_1 data;
    struct LNode *next;
} LNode, *LinkList;

//Function definition
Status InitLinklist(LinkList &, int);
void DisplayLinkList(LinkList);
Status SortLinkList(LinkList &);
Status MergeLinkList(LinkList, LinkList, LinkList &);

//Function realization
//Init a new linklist
/**
 * receive:
 *  &L : The linklist which u want to initialization.
 *  num : The total length of this linklist.
 * return:
 *  Status : The status of this initialization.
*/
Status InitLinklist(LinkList &L, int num = 0)
{
    //Check to see if the variable is legal
    if (num < 0)
        return ERR;

    L = new LNode;    //Set L to a new head node of the linklist
    (*L).next = NULL; //Set the L next point to a null value

    //Insert it in its head
    while (num--)
    {
        cout << "Please input the element which postion is " << num + 1 << endl;
        LNode *p = new LNode; //Dynamically open up a new node
        cin >> p->data;       //Get the data of the new node
        p->next = L->next;    //Change this node's next point to the head point of this linklist's head
        L->next = p;          //Let the linklist's next point pointed to the new node next point
    }
    return DONE;
}
//Display the element of the linklist to the screen
/**
 * recieve:
 *  L : The linklist.
*/
void DisplayLinkList(LinkList L)
{
    while (L->next) //If the next pint is exist
    {
        cout << L->next->data; //Print the data of it
        cout << "\t";
        L = L->next; //To next point
    }
    cout << endl;
}
//Sort the linklist u put in
/**
 * recieve:
 *  &L : The linklist we should sort.
 * return : 
 *  Status : The status whether it is done or false.
*/
Status SortLinkList(LinkList &L)
{
    /**
     * I do not know how to explain it,
     * but actually, it is a bit hard for me.
     * So at this moment, i decided to
     * play computer games!!!
     * 
     * I am sorry that i do not play game,
     * but i watch a movie The Pianist.
     * I like it, that is all. 
    */

    //Check the variavle legalcy
    if (!L->next)
        return ERR;

    LNode *pPrior = L->next;     //Set the pPrior to the first node
    LNode *pNext = pPrior->next; //Set the pNext to the seconde node

    LNode *temp; //The temporary variable for swap

    pPrior->next = NULL; //Let the linklist cut down between the first one and the second one
    pPrior = L;          //Let the pPrior be the L

    //For each pNext
    while (pNext)
    {
        //Let temp point to the next point
        temp = pNext->next;

        //Find the correct place to insert the element
        while (pPrior->next->data < pNext->data)
        {
            pPrior = pPrior->next;
        }

        //Insert it to linklist
        pNext->next = pPrior->next;
        pPrior->next = pNext;
        pNext = temp;

        //Let the for circulation start over again
        pPrior = L;
    }

    //Return the correct message
    return DONE;
}
//Merge the two sortedlinklist L1 and L2 to a new linklist L3
Status MergeLinkList(LinkList L1, LinkList L2, LinkList &L3)
{
    //Let L3 be a new linklist
    InitLinklist(L3);

    //Variable definition
    LNode *pNode, *qNode, *rNode;
    pNode = L1->next;
    qNode = L2->next;
    rNode = L3;

    //Foreach this two linklist
    while (pNode && qNode)
    {
        //Make new node to save the message
        LNode *InsertNode = new LNode;

        //Insert
        if (pNode->data < qNode->data)
        {
            InsertNode->data = pNode->data;
            //InsertNode->next = rNode->next;
            InsertNode->next = NULL;
            rNode->next = InsertNode;
            pNode = pNode->next;
            rNode = rNode->next;
        }
        else
        {
            InsertNode->data = qNode->data;
            //InsertNode->next = rNode->next;
            InsertNode->next = NULL;
            rNode->next = InsertNode;
            qNode = qNode->next;
            rNode = rNode->next;
        }

        //Exclude duplication options
        while (pNode && pNode->data == rNode->data)
        {
            pNode = pNode->next;
            continue;
        }
        while (qNode && qNode->data == rNode->data)
        {
            qNode = qNode->next;
            continue;
        }
    }

    //If still left
    if (pNode)
    {
        rNode->next = pNode;
    }
    if (qNode)
    {
        rNode->next = qNode;
    }
    return DONE;
}