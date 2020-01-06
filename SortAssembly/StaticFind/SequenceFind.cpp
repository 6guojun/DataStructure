/**
 * 带哨兵的顺序查找
*/
#include <iostream>
#include <time.h>

using namespace std;

#define random(x) (rand() % x)

void InitRandomTable(int t[], int n);
void ShowTable(int t[], int n);
int Search(int t[], int n, int s);

int main()
{
    int Hello[20];
    InitRandomTable(Hello, 20);
    ShowTable(Hello, 20);
    cout << Search(Hello, 20, 101);

    return 0;
}

void InitRandomTable(int t[], int n)
{
    srand((int)time(0)); //设置随机数种子
    for (int i = 0; i < n; i++)
    {
        t[i] = random(100);
    }
}

void ShowTable(int t[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << t[i] << " ";
    }
    cout << endl;
}

int Search(int t[], int n, int s)
{
    t[0] = s;
    int i;
    for (i = n - 1; t[i] != s; i--)
        ;
    return i;
}