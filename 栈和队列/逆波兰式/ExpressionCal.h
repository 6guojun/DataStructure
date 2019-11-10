#pragma once
/**
 * 编译说明：
 * %这里并未进行限制，因而即使是小数也依然可以进行取模操作，但实际上的操作为转化为整数取模
 * 
 * 拓展了十进制小数、八进制整数、十六进制整数、科学计数法
 * 
*/

#include <iostream>
#include <string>
#include <cmath>
#include "OperatorPriority.h"
#include "OperatorStack.h"
#include "DigitalStack.h"
#include "CommonSetting.h"

using namespace std;

//函数定义
//判断是否为数字/小数点/符号
//参数:
//  c : 输入的字符
//返回:
//  bool : 是否为符号/数字/小数点
bool IsDigital(char c, bool IsHEX = false)
{
    return ((c >= '0' && c <= '9') ||
            (IsHEX &&
             ((c >= 'a' && c <= 'e') ||
              (c >= 'A' && c <= 'E'))));
}
bool IsPoint(char c)
{
    return (c == '.');
}
bool IsOperator(char c)
{
    return InStackOperator.find(c) != InStackOperator.end();
}
//八进制十六进制转化为十进制
//参数:
//  num : 输入的数字
//  type : 原本的进制
//返回:
//  double : 参与计算的数
double IntConvert(int num, int type)
{
    int convert = 0;
    int degree = 1;
    int multiple = 10;
    do
    {
        convert += (num % multiple) * degree;
        degree *= type;
        num /= multiple;
    } while (num * 10 / multiple != 0);
    return convert;
}
//获取字符串中的数字
//参数:
//  str : 输入的字符串
//  pla : 数字起始位置
//返回:
//  bool : 是否为符号/数字
//  pla : 数字终止位置
double GetDigital(string str, int &pla)
{
    char c = str[pla];

    bool IsFloat = false;
    int base = 10;
    double num = 0;
    double multiple = 1;
    bool IsOct = false;
    bool IsHex = false;

    //判断进制
    if (c == '0' && (!IsOperator(str[pla + 1])) && (!IsPoint(str[pla + 1])))
    {
        if (str[pla + 1] == 'X' || str[pla + 1] == 'x')
        {
            IsHex = true;
            c = str[++++pla];
            base = 16;
        }
        else
        {
            IsOct = true;
            c = str[++pla];
            base = 8;
        }
    }

    //获得数字
    while (c != '\0' && (IsDigital(c, IsHex) || IsPoint(c)))
    {
        cout << c << endl;
        //小数点
        if (IsPoint(c))
        {
            //多个小数点
            if (IsFloat || IsHex || IsOct)
            {
                cout << "Your data is illegal!" << endl;
                exit(0);
            }
            IsFloat = true;
            //跳过当前节点
            c = str[++pla];
            continue;
        }

        //如果处于小数状态
        if (IsFloat)
        {
            multiple *= 10;
        }

        int CurNum = IsDigital(c) ? c - '0' : (c >= 'a' && c <= 'e') ? c - 'a' + 10 : c - 'A' + 10;
        if (CurNum >= base)
        {
            cout << "Num is not in base " << base << endl;
            exit(0);
        }

        num = base * num + CurNum; //获取数字
        c = str[++pla];
    }
    pla--;
    return num / multiple;
}
//计算表达式
//参数:
//  pre : 被操作数
//  las : 操作数
//  o : 操作符
//返回:
//  int : 计算结果
double Cal(double pre, char o, double las)
{
    switch (o)
    {
    case '+':
        return pre + las;
    case '-':
        return pre - las;
    case '*':
        return pre * las;
    case '/':
        return pre / las;
    case '%':
        return (double((int)pre % (int)las));
    case '^':
        return pow(pre, las);
    case 'e':
    case 'E':
        return pre * pow(10, las);
    default:
        cout << "Cal is Error！" << endl;
        exit(0);
    }
}
Status CalExpression(string str)
{
    //字符串尾部加上结束符与栈底对应
    str += "#";

    //初始化符号栈和操作数栈
    OperatorStack OpStack;
    DigitalStack DigStack;
    InitStack(OpStack);
    InitStack(DigStack);

    for (int i = 0; str[i] != '\0'; i++)
    {
        char c = str[i];

        //如果为操作数
        if (IsDigital(c))
        {
            Push(DigStack, GetDigital(str, i));
            cout << "Digital:\t" << DigStack.Stack[DigStack.Top - 1] << endl;
            continue;
        }

        //如果为运算符
        if (IsOperator(c))
        {
            //当前操作符(在外部)
            Operator CurOp = GetOperatorOut(c);
            //前一个操作数(在内部、已经形成)
            Operator PreOp = OpStack.Stack[OpStack.Top - 1];
            cout << "Operator:\t" << c << endl;

            //当前操作符优先级等于前一个操作数优先级（等于仅发生在两个 # ）
            if (CurOp.prior == PreOp.prior)
            {
                //括号匹配
                if (CurOp.Operator == ')')
                {
                    Operator POP;
                    Pop(OpStack, POP);
                    if (POP.Operator != '(')
                    {
                        exit(0);
                    }
                }
                if (CurOp.Operator == '#')
                {
                    //设置栈空，可说明计算成功，表达式无错误
                    OpStack.Top = 0;
                }
            }
            //当前操作符优先级高于前一个操作数优先级
            if (CurOp.prior > PreOp.prior)
            {
                Push(OpStack, c);
                cout << "\tPush:\t\t" << c << endl;
            }
            //当前操作符优先级低于前一个操作数优先级
            if (CurOp.prior < PreOp.prior)
            {
                double PreDig, OprDig;
                Operator CalOp;

                Pop(OpStack, CalOp);
                Pop(DigStack, OprDig);
                Pop(DigStack, PreDig);

                Push(DigStack, Cal(PreDig, CalOp.Operator, OprDig));
                cout << "\tCal:\t\t" << Cal(PreDig, CalOp.Operator, OprDig) << endl;
                i--;
            }
        }
    }

    //如果操作数栈只有一个元素，操作符栈没有元素
    if (DigStack.Top == 1 && OpStack.Top == 0)
        cout << "RESULT:\t" << DigStack.Stack[0];
    else
    {
        cout << "Waiting for fixed the bug.";
    }

    return DONE;
}
