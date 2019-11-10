#pragma once

//引入头文件
#include <iostream>
#include <string>
//引入自定义头文件
#include "CommonSetting.h"
#include "BaseStack.h"

//引入命名空间
using namespace std;

//操作数栈结构体定义
typedef struct
{
    double Stack[MAXSIZE];
    int Top;
    int StackSize;
} DigitalStack;

//函数定义
//初始化符号栈
//参数:
//  S : 为一个符号栈，传值引用保证其可修改
//返回:
//  Status : 函数执行状况
Status InitStack(DigitalStack &S)
{
    S.Top = 0;
    S.StackSize = MAXSIZE;
    return DONE;
}
//符号栈压栈
//参数:
//  S : 为一个符号栈，传值引用保证其可修改
//  o : 运算符的字符，栈内将其更改为运算符
//返回:
//  Status : 函数执行状况
Status Push(DigitalStack &S, double e)
{
    //栈满报错，并终止程序
    if (S.Top >= S.StackSize)
    {
        cout << "Error in Function( Push ) : Your stack is overflow!";
        exit(0);
        //return ERR;
    }

    //压入栈内
    S.Stack[S.Top++] = e;
    return DONE;
}
//符号栈出栈
//参数:
//  S : 为一个符号栈，传值引用保证其可修改。
//返回:
//  Status : 函数执行状况
//  e : 返回弹出的元素
Status Pop(DigitalStack &S, double &e)
{
    //栈空报错，并终止程序
    if (S.Top <= 0)
    {
        cout << "Error in Function( Pop ) : Your stack is empty!";
        exit(0);
        //return ERR;
    }

    //元素出栈并把出栈元素赋值给e
    e = S.Stack[--S.Top];
    return DONE;
}