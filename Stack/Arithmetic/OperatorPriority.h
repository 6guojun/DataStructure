#pragma once
/**
 * 编译说明：
 * 这个头文件中包含了运算符号的定义，定义中包含运算符的操作符和优先级
 * 由于优先级在栈内和栈外并不相同，因此我们定义了一个函数获得栈内外的优先级等级
 * 由于一般习惯，我们优先从左边算起，所以容易得到，栈内的加减乘除取余平方等操作，优先级低于栈外
 * 同时括号的优先级等级在栈内外互换，栈外左括号强于右括号，栈内右括号强于左括号
 * 
 * 符号：   +   -   *   /   %   ^   e   E   (   )   #
 * 栈外：   3   3   5   5   5   7   9   9   10  1   0
 * 栈内：   2   2   4   4   4   6   8   8   1   10  0
 * 
 * 由此我们就可以完全确定运算符的优先级，并进行定义。
*/

//引入头文件
#include <iostream>
#include <map>

//引入命名空间
using namespace std;

//定义运算符
typedef struct
{
    char Operator; //操作符
    int prior;     //优先级
} Operator;

//优先级表格
//这里我采用了键值对Map的形式，原版本写的内容为Switch，因为个人觉得这样写起来更方便，所以这里采用键值对
map<char, int> InStackOperator = {
    {'+', 3}, {'-', 3}, {'*', 5}, {'/', 5}, {'%', 5}, {'^', 7}, {'e', 9}, {'E', 9}, {'(', 1}, {')', 8}, {'#', 0}};
map<char, int> OutStackOperator = {
    {'+', 2}, {'-', 2}, {'*', 4}, {'/', 4}, {'%', 4}, {'^', 6}, {'e', 8}, {'E', 8}, {'(', 8}, {')', 1}, {'#', 0}};

//函数定义
//获取栈内运算符
//参数：
//  op - 运算符的字符
//返回：
//  Operator - 运算符结构
Operator GetOperatorIn(char o)
{
    map<char, int>::iterator FindResult;

    //查找o所代表的符号是否存在于键值对表格中
    FindResult = InStackOperator.find(o);
    if (FindResult == InStackOperator.end())
    {
        //符号不合法，报错并终止程序
        cout << "Error in Function( GetOperatorIn ) : Your expression is illegal!";
        exit(0);
    }
    else
    {
        //返回符号
        Operator Op;
        Op.Operator = o;
        Op.prior = InStackOperator[o];
        return Op;
    }
}
//获取栈外运算符
//参数：
//  op - 运算符的字符
//返回：
//  Operator - 运算符结构
Operator GetOperatorOut(char o)
{
    map<char, int>::iterator FindResult;

    //查找o所代表的符号是否存在于键值对表格中
    FindResult = OutStackOperator.find(o);
    if (FindResult == OutStackOperator.end())
    {
        //符号不合法，报错并终止程序
        cout << "Error in Function( GetOperatorOut ) : Your expression is illegal!";
        exit(0);
    }
    else
    {
        //返回符号
        Operator Op;
        Op.Operator = o;
        Op.prior = OutStackOperator[o];
        return Op;
    }
}