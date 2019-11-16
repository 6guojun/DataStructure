#include "BinaryTree.h"

int main()
{
    BiTree root;

    //ABD#E###CFG###H##
    //Pre order:ABDECFGH
    //In order:DEBAGFCH
    //Post order:EDBGFHCA
    cout << "Input ebt:" << endl;
    CreatBiTree_Rec(root);

    cout << "Pre order:" << endl;
    DisplayBiTree_Stack(root, Pre);
    cout << endl;
    DisplayBiTree(root, Pre);
    cout << endl;

    cout << "In order:" << endl;
    DisplayBiTree_Stack(root, In);
    cout << endl;
    DisplayBiTree(root, In);
    cout << endl;

    cout << "Post order:" << endl;
    DisplayBiTree_Stack(root, Post);
    cout << endl;
    DisplayBiTree(root, Post);
    cout << endl;

    return 0;
}