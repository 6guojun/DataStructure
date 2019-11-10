//Include some library.
#include "BinaryTree.h"

//Function entrance.
int main()
{
    /**
     * Introduce:
     * 1, Test input: AB#C##DE#F##G##
    */

    //State a BiTree.
    BiTree b;

    //Recursion type.
    //CreatBiTree_Recursion(b);
    //ShowBiTree(b);
    //cout << endl;

    //Ergodic type.
    CreatBiTree_Ergodic(b);
    ShowBiTree(b);

    return 0;
}