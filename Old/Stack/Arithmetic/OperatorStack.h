#pragma once
/**
 * 编译说明：
 * 在本头文件中直接进行了结构体的赋值，在此处是允许的，但必须说明的以下要点：
 * 结构体的赋值仅仅是简单的浅复制，如果涉及到指针类型就会出问题，在有指针的情况下会出现指向同一位置的情况。
 * 如果另外一个变量内存释放，则该指针可能变成野指针。
 * 
 * 本符号栈压栈直接传入字符即可完成压栈，一切转换都在函数内部完成。
*/

//引入头文件
#include <iostream>
//引入自定义头文件
#include "CommonSetting.h"
#include "BaseStack.h"
#include "OperatorPriority.h"

//引入命名空间
using namespace std;

//符号栈结构体定义
typedef struct
{
    Operator Stack[MAXSIZE];
    int Top;
    int StackSize;
} OperatorStack;

//函数定义
//初始化符号栈
//参数:
//  S : 为一个符号栈，传值引用保证其可修改
//返回:
//  Status : 函数执行状况
Status InitStack(OperatorStack &S)
{
    //这里需要进行判断内存空间是否充足
    S.Top = 1;
    S.Stack[0] = GetOperatorIn('#'); //此处直接赋值，详细请看编译说明
    S.StackSize = MAXSIZE;
    return DONE;
}
//符号栈压栈
//参数:
//  S : 为一个符号栈，传值引用保证其可修改
//  o : 运算符的字符，栈内将其更改为运算符
//返回:
//  Status : 函数执行状况
Status Push(OperatorStack &S, char o)
{
    //栈满报错，并终止程序
    if (S.Top >= S.StackSize)
    {
        cout << "Error in Function( Push ) : Your stack is overflow!";
        exit(0);
        //return ERR;
    }

    //压入栈内
    S.Stack[S.Top++] = GetOperatorIn(o);
    return DONE;
}
//符号栈出栈
//参数:
//  S : 为一个符号栈，传值引用保证其可修改。
//返回:
//  Status : 函数执行状况
//  o : 返回弹出的元素
Status Pop(OperatorStack &S, Operator &o)
{
    //栈空报错，并终止程序
    if (S.Top <= 0)
    {
        cout << "Error in Function( Pop ) : Your stack is empty!";
        exit(0);
        //return ERR;
    }

    //元素出栈并把出栈元素赋值给o
    o = S.Stack[--S.Top];
    return DONE;
}