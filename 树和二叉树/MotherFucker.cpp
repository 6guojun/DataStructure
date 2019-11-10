#include <iostream>
#include <stack>
#include <string>

using namespace std;

class BiNode
{
public:
    BiNode(){};
    BiNode(char c) : val(c){};
    char val;
    BiNode *left = NULL;
    BiNode *right = NULL;
};

BiNode *addTree(string str)
{
    BiNode *root = new BiNode(str[0]);
    stack<BiNode *> stk;
    stk.push(root);
    int id = 1;
    bool A = false;
    while (!stk.empty())
    {
        if (stk.top()->left == NULL && str[id - 1] != '#')
        {
            if (str[id] != '#')
            {
                BiNode *left = new BiNode(str[id]);
                stk.top()->left = left;
                stk.push(left);
            }
            id++;
        }
        else
        {
            if (stk.top()->right == NULL)
            {
                if (str[id] != '#')
                {
                    BiNode *right = new BiNode(str[id]);
                    stk.top()->right = right;
                    stk.push(right);
                }
                else
                {
                    stk.pop();
                }
                id++;
            }
            else
            {
                stk.pop();
            }
        }
    }
    return root;
}

void printTree(BiNode *root)
{
    if (root != NULL)
    {
        cout << root->val;
        if (root->left != NULL)
        {
            printTree(root->left);
        }
        if (root->right != NULL)
        {
            printTree(root->right);
        }
    }
}

int main()
{
}