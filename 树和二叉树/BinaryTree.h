//Include Liberary.
#include <iostream>
#include <stack>

//Import the namespace.
using namespace std;

//Define the binary tree struction.
typedef struct BiNode
{
    char data;
    struct BiNode *LeftChild;
    struct BiNode *RightChild;
} BiNode, *BiTree;

//Pre-order creat binary tree.
void CreatBiTree_Rec(BiTree &root)
{
    //Get the input.
    char c;
    cin >> c;

    switch (c)
    {
    case '#':
        root = NULL;
        break;
    default:
        //Creat a new root.
        root = new BiNode;
        //Set its left child and right child be null.
        root->LeftChild = root->RightChild = NULL;
        //Set the data value.
        root->data = c;
        //Recursively generated child tree.
        CreatBiTree_Rec(root->LeftChild);
        CreatBiTree_Rec(root->RightChild);
        break;
    }
}

//Loop to creat binary tree.
void CreatBiTree_Loop(BiTree &root)
{
    stack<BiTree> BiStack;

    while (true)
    {
    }
}

enum Type
{
    Pre,
    In,
    Post
};

void DisplayBiTree(BiTree root, enum Type t)
{
    if (!root)
    {
        return;
    }
    if (t == Pre)
    {
        cout << root->data;
    }
    DisplayBiTree(root->LeftChild, t);
    if (t == In)
    {
        cout << root->data;
    }
    DisplayBiTree(root->RightChild, t);
    if (t == Post)
    {
        cout << root->data;
    }
}

void DisplayBiTree_Stack(BiTree root, enum Type t)
{
    stack<BiTree> BiStack;
    BiNode *p = root, *temp = NULL;
    do
    {
        if (!p)
        {
            p = BiStack.top();
            if (t != Post)
            {
                BiStack.pop();
            }
            if (t == In)
            {
                cout << p->data;
            }
            if (t == Post)
            {
                if (!p->RightChild || p->RightChild == temp)
                {
                    cout << p->data;
                    BiStack.pop();
                    temp = p;
                    p = NULL; //This is important.
                    continue;
                }
            }
            p = p->RightChild;
            continue;
        }

        //cout << p->data;
        BiStack.push(p);
        if (t == Pre)
        {
            cout << p->data;
        }
        p = p->LeftChild;

    } while (!BiStack.empty() || p);
}