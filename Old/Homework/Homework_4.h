#include <iostream>
#include <string>
#include "StatusConfigration.h"

using namespace std;

#define MAXSIZE 100

//Struct definition
typedef struct Mtacher
{
    string Container[MAXSIZE];
    int Top;
    int listsize;
} MatchStack;

//Function definition
Status Push(MatchStack &S, string matcher)
{
    if (S.Top >= S.listsize)
    {
        return ERR;
    }
    S.Container[S.Top++] = matcher;
    return DONE;
}

Status Pop(MatchStack &S, string &e)
{
    if (S.Top <= 0)
    {
        return ERR;
    }
    e = S.Container[S.Top--];
    return DONE;
}

Status InitStack(MatchStack &S)
{
    S.Container[0] = "#";
    S.listsize = MAXSIZE;
    S.Top = 1;
    return DONE;
}

Status matchMatcher(MatchStack &S, string input)
{
    InitStack(S);

    input += "#";
    string e;

    for (int i = 0; input[i] != '\0'; i++)
    {
        if ((input[i] == '(') && (Push(S, "(") == ERR))
        {
            return ERR;
        }
        if ((input[i] == ')') && (Pop(S, e) == ERR))
        {
            return ERR;
        }
    }
    return (S.Top == 1) ? DONE : ERR;
}