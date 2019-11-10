/**
 * This is about unary system of quadratic equation
*/

//import library
#include <iostream>
#include "StatusConfigration.h"

//import namespace
using namespace std;

//Struction definition
/**
 * Using:
 *  LNode : One node for the linklist it belong to.
 *  LinkList : Always a head of a linklist.
*/
typedef struct eNode
{
    int coef; //coefficient
    int pow;  //pow degree
    struct eNode *next;
} eNode, *equation;

//Function definition
Status InitEquation(equation &, int);
void DisplayEquation(equation);
Status SortEquation(equation &);
Status MergeEquation(equation, equation, equation &);

//Function realization
Status InitEquation(equation &E, int len = 0)
{
    //Check the variable legalcy
    if (len < 0)
    {
        return ERR;
    }

    //New a node and make the next be null
    E = new eNode;
    E->next = NULL;

    //Insert it in its head
    while (len--)
    {
        cout << "Please input the element which postion is " << len + 1 << endl;
        eNode *p = new eNode; //Dynamically open up a new node

        //Input the coefficient and the pow degree
        cout << "\t Coefficient:";
        cin >> p->coef;
        cout << "\t Pow degree:";
        cin >> p->pow;

        p->next = E->next; //Change this node's next point to the head point of this equation's head
        E->next = p;       //Let the equation's next point pointed to the new node next point
    }
    return DONE;
}
void DisplayEquation(equation E)
{
    cout << "Q(p) = ";
    while (E->next) //If the next pint is exist
    {
        cout << E->next->coef << "*q^" << E->next->pow;
        E = E->next; //To next point
        if (E->next)
        {
            cout << "+";
        }
    }
    cout << endl;
}
Status SortEquation(equation &E)
{
    //Check the variavle legalcy
    if (!E->next)
        return ERR;

    eNode *pPrior = E->next;     //Set the pPrior to the first node
    eNode *pNext = pPrior->next; //Set the pNext to the seconde node

    eNode *temp; //The temporary variable for swap

    pPrior->next = NULL; //Let the linklist cut down between the first one and the second one
    pPrior = E;          //Let the pPrior be the L

    //For each pNext
    while (pNext)
    {
        //Let temp point to the next point
        temp = pNext->next;

        //Find the correct place to insert the element
        while (pPrior->next->pow < pNext->pow)
        {
            pPrior = pPrior->next;
        }

        //Insert it to linklist
        pNext->next = pPrior->next;
        pPrior->next = pNext;
        pNext = temp;

        //Let the for circulation start over again
        pPrior = E;
    }

    //Return the correct message
    return DONE;
}
Status MergeEquation(equation E1, equation E2, equation &E3)
{
    //Let L3 be a new linklist
    InitEquation(E3);

    //Variable definition
    eNode *pNode, *qNode, *rNode;
    pNode = E1->next;
    qNode = E2->next;
    rNode = E3;

    //Foreach this two linklist
    while (pNode && qNode)
    {
        //Make new node to save the message
        eNode *InsertNode = new eNode;

        //Here we can have a selection between pNode & qNode, use bool:ex1?ex2 this form.
        //Insert
        if (pNode->pow < qNode->pow)
        {
            InsertNode->pow = pNode->pow;
            InsertNode->coef = pNode->coef;
            //InsertNode->next = rNode->next;
            InsertNode->next = NULL;
            rNode->next = InsertNode;
            pNode = pNode->next;
            rNode = rNode->next;
        }
        else
        {
            InsertNode->pow = qNode->pow;
            InsertNode->coef = qNode->coef;
            //InsertNode->next = rNode->next;
            InsertNode->next = NULL;
            rNode->next = InsertNode;
            qNode = qNode->next;
            rNode = rNode->next;
        }

        //Exclude duplication options
        while (pNode && pNode->pow == rNode->pow)
        {
            rNode->coef += pNode->coef;
            pNode = pNode->next;
            continue;
        }
        while (qNode && qNode->pow == rNode->pow)
        {
            rNode->coef += qNode->coef;
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