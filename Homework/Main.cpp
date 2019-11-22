//调用库
#include <iostream>
#include "Homework_1.h"
#include "Homework_2.h"
#include "Homework_3.h"
#include "Homework_4.h"

//引入命名空间
using namespace std;

//宏定义
#define MinSel 1
#define MaxSel 2

//函数定义
int PrintSelecPanel();       //显示选择面板
void PrintHomeworkPanel_1(); //显示作业1面板
void PrintHomeworkPanel_2(); //显示作业2面板
void PrintHomeworkPanel_3(); //显示作业3面板
void PrintHomeworkPanel_4(); //显示作业3面板

//主函数入口
int main()
{
    //退出标志
    int flag = true;

    while (flag)
    {
        //变量定义
        int sel;

        //函数执行
        sel = PrintSelecPanel();

        switch (sel)
        {
        case 1:
            PrintHomeworkPanel_1();
            break;
        case 2:
            PrintHomeworkPanel_2();
            break;
        case 3:
            PrintHomeworkPanel_3();
            break;
        case 4:
            PrintHomeworkPanel_4();
            break;
        default:
            flag = false;
            break;
        }
    }

    return 0;
}

//函数实现
//选择作业次数面板
int PrintSelecPanel()
{
    //选择标号
    int selection;
    //输出内容
    cout << "This is a simple test for my homwwork, so now please select one which u want to test." << endl
         << "\t 1 \t"
         << "LinkList" << endl
         << "\t 2 \t"
         << "Unary system of quadratic equations (Linklist Realization)" << endl
         << "\t 3 \t"
         << "Unary system of quadratic equations (SqList)" << endl;
    //输入选择
    cin >> selection;
    //返回
    return selection;
}
//选择第一次作业面板
void PrintHomeworkPanel_1()
{
    //Data definition
    LinkList L1, L2, L3;
    int len1, len2;

    //Init L1 and output it
    cout << "Init a linklist named L1..." << endl;
    {
        cout << "Len of this linklist: ";
        cin >> len1;
        InitLinklist(L1, len1);
    }
    cout << "Linklist L1 is finished." << endl;
    cout << "Inited linklist:";
    DisplayLinkList(L1);
    cout << "Sorted linklist:";
    SortLinkList(L1);
    DisplayLinkList(L1);

    cout << endl;

    //Init L1 and output it
    cout << "Init a linklist named L2..." << endl;
    {
        cout << "Len of this linklist: ";
        cin >> len2;
        InitLinklist(L2, len2);
    }
    cout << "Linklist L2 is finished." << endl;
    cout << "Sorted linklist:";
    SortLinkList(L2);
    DisplayLinkList(L2);

    cout << endl;

    //Merge L1 and L2 to L3
    cout << "Now we merge L1 and L2 to L3..." << endl;
    MergeLinkList(L1, L2, L3);
    cout << "Merged linklist:";
    DisplayLinkList(L3);
}
//选择第二次作业面板
void PrintHomeworkPanel_2()
{
    equation E1, E2, E3;
    int len1, len2;

    cout << "Init a new equation..." << endl;
    cout << "Input the max poiw degree: ";
    cin >> len1;
    InitEquation(E1, len1);
    cout << "The equation u init: ";
    DisplayEquation(E1);
    cout << "The equtaion u sorted: ";
    SortEquation(E1);
    DisplayEquation(E1);

    cout << "Init a new equation..." << endl;
    cout << "Input the max poiw degree: ";
    cin >> len2;
    InitEquation(E2, len2);
    cout << "The equation u init: ";
    DisplayEquation(E2);
    cout << "The equtaion u sorted: ";
    SortEquation(E2);
    DisplayEquation(E2);

    cout << "Now we merge them: ";
    MergeEquation(E1, E2, E3);
    DisplayEquation(E3);
}
//选择第三次作业面板
void PrintHomeworkPanel_3()
{
    EquationList E, EE;
    InitEquationList(E, 5);
    DisplayEquationList(E);
    MergeList(E, E, EE);
    DisplayEquationList(EE);
}
//选择第四次作业面板
void PrintHomeworkPanel_4()
{
    MatchStack S;
    matchMatcher(S, "(())");
}