//import library
#include <iostream>
#include "StatusConfigration.h"

//import namespace
using namespace std;

//Marco definition
#define MAXSIZE 100

//Struction definition
typedef struct EquationList
{
    int coef[MAXSIZE];
    int len;
    int listsize;
} EquationList;

//Function definition
Status InitEquationList(EquationList &E, int len = 0)
{
    if (len < 0)
    {
        return ERR;
    }

    E.len = len;
    while (len > 0)
    {
        cin >> E.coef[len - 1];
        len--;
    }
    return DONE;
}
void DisplayEquationList(EquationList E)
{
    for (int i = 0; i < E.len; i++)
    {
        if (E.coef[i] != 0)
        {
            cout << E.coef[i] << "*p^" << i;
        }
        if (i + 1 < E.len)
        {
            cout << " + ";
        }
    }
    cout << endl;
}
void MergeList(EquationList E1, EquationList E2, EquationList &E3)
{
    InitEquationList(E3);
    for (int i = 0; i < E1.len || i < E2.len; i++)
    {
        E3.len++;
        E3.coef[i] = E1.coef[i] + E2.coef[i];
    }
    return;
}