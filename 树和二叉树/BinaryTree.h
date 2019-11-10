/**
 * Introduce:
 * 1, We use char '#' to behalf the null node.
*/

//Include some library.
#include <iostream>
#include <string>
#include <stack>

//Imprt the namespace to this file.
using namespace std;

//Marco define.
#define MAXSIZE 100

//Define a struct to behalf the BinaryTree.
typedef struct BiNode
{
    struct BiNode *LeftChild;
    char Data;
    struct BiNode *RightChild;
} BiNode, *BiTree;

//Expanding the first ordered binary tree

//Creat BiNode.
//recieves:
//  BiNode *&BN : The node u want to open.
//  char c : The data u want to push in.
//returns:
// None
void CreatBiNode(BiNode *&BN, char c)
{
    //Open a new node.
    BN = new BiNode;
    cout << "Now we new a new node." << c << endl;

    //Push the char into data.
    BN->Data = c;
    cout << "Push:\t" << BN->Data << endl;
}

//Generating binary tree by recursion.
//recieves:
//  BiTree &B : The node we should allocate memory space.
//returns:
//  None
void CreatBiTree_Recursion(BiTree &B)
{
    //Get the new node tag.
    char s;
    cin >> s;

    //Determine the char entered.
    switch (s)
    {
    //The node will be null.
    case '#':
        B = NULL;
        break;
    //The node is not null.
    default:
        //Creat a new node which data is s.
        CreatBiNode(B, s);

        //Start recursion.
        CreatBiTree_Recursion(B->LeftChild);
        CreatBiTree_Recursion(B->RightChild);
        break;
    }
}

//Define a stack of BiTree.
typedef struct BiTreeStack
{
    BiNode *Stack[MAXSIZE];
    int Top;
    int Size;
} BiTreeStack;

//Init a BiTreeStack.
void InitBiTreeStack(BiTreeStack &BTS)
{
    BTS.Top = 0;
    BTS.Size = MAXSIZE;
}

//Push to BiTreeStakc.
void Push(BiTreeStack &BTS, BiNode *c)
{
    //Safety inspection.
    if (BTS.Top >= BTS.Size)
    {
        cout << "The stakc is full" << endl;
        return;
    }

    //Push in.
    //Creat a new node which data is s
    BTS.Stack[BTS.Top++] = c;
    return;
}

//Pop from BiTreeStakc.
void Pop(BiTreeStack &BTS, BiNode *&c)
{
    /*
    //Safety inspection.
    if (BTS.Top <= 0)
    {
        cout << "The stakc is full" << endl;
        return;
    }
    */

    //Pop it.
    c = BTS.Stack[--BTS.Top];
    return;
}

void CreatBiTree_Ergodic(BiTree &B)
{
    //Init a stack.
    BiTreeStack BTS;
    InitBiTreeStack(BTS);

    //Define a pointer to do many thing.
    B = new BiNode;
    BiNode *pB = B;
    pB->Data = getchar();
    cout << "GET\t" << pB->Data << endl;
    //Push in.
    Push(BTS, pB);
    cout << "PUSH\t" << pB->Data << endl;

    //This condition is not well-defined.
    char c;
    bool isRight = false;
    while (c = getchar())
    {
        switch (c)
        {
        case '#':
            //If null stack then end.
            if (BTS.Top == 0)
            {
                return;
            }
            //pB revoke.
            Pop(BTS, pB);
            cout << "POP\t" << pB->Data << endl;
            isRight = true;
            break;
        default:
            if (!isRight)
            {
                pB->LeftChild = new BiNode;
                pB = pB->LeftChild;
            }
            else
            {
                pB->RightChild = new BiNode;
                pB = pB->RightChild;
            }

            //Tag the pB.
            pB->Data = c;
            pB->LeftChild = pB->RightChild = NULL;
            cout << "GET\t" << c << endl;

            //Push in.
            Push(BTS, pB);
            cout << "PUSH\t" << pB->Data << endl;

            cout << "DIR\t" << (isRight ? "Right" : "Left") << endl;

            isRight = false;
            break;
        }
    }

    return;
}

void ShowBiTree(BiTree &B)
{
    if (!B)
    {
        return;
    }
    cout << B->Data << " ";
    ShowBiTree(B->LeftChild);
    ShowBiTree(B->RightChild);
    return;
}

void ShowTree_Ergodic(BiTree B)
{
    //Init a stack.
    BiTreeStack BTS;
    InitBiTreeStack(BTS);

    //左可左入栈，tag初始0
    //无根出栈一，tag++
    //tag==1，转向看入栈
    //tag==2，出栈继续走

    //因为要维护一个Stack，所以我不写了
    
}