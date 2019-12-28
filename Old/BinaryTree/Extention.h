#pragma once

#include "BinaryTree.h"
#include <string>

void UnionPreIn(string Pre, string In, BiTree &root)
{
    //Pre order:ABDECFGH
    //In order:DEBAGFCH
    root = new BiNode;
    root->data = Pre[0];
    string left, right;

    int rootPos = In.find(Pre[0]);
    left = In.substr(0, rootPos);
    right = In.substr(rootPos + 1, In.length());

    int lLength = left.length();
    int rLength = right.length();

    root->LeftChild = root->RightChild = NULL;

    if (lLength != 0)
    {
        cout << "LEFT" << endl;
        cout << '\t' << Pre.substr(1, lLength) << " " << left << endl;

        root->LeftChild = new BiNode;
        cout << root->data << "l" << Pre.substr(1, lLength)[0] << endl;
        root->LeftChild->data = Pre.substr(1, lLength)[0];
        UnionPreIn(Pre.substr(1, lLength), left, root->LeftChild);
    }

    if (rLength != 0)
    {
        cout << "RIGHT" << endl;
        cout << '\t' << Pre.substr(Pre.length() - rLength, Pre.length()) << " " << right << endl;

        root->RightChild = new BiNode;
        cout << root->data << "r" << Pre.substr(Pre.length() - rLength, Pre.length())[0] << endl;
        root->RightChild->data = Pre.substr(Pre.length() - rLength, Pre.length())[0];
        UnionPreIn(Pre.substr(Pre.length() - rLength, Pre.length()), right, root->RightChild);
    }
}