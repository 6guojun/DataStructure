/**
 * 带哨兵的顺序查找
*/
#include <iostream>
#include <time.h>

using namespace std;

#define random(x) (rand() % x)

void InitRandomTable(int t[], int n);
void ShowTable(int t[], int n);

int main()
{
    int Hello[20], Do[20];
    InitRandomTable(Hello, 20);
    ShowTable(Hello, 20);

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

void CreatBST(int t[], int b[], int n)
{
    b[0] = t[0];
    int cur = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= cur; j++)
        {
            if (t[i] > b[i])
            {
                if (2 * i + 1 > cur)
                {
                    j = 2 * i + 1;
                }
                else
                {
                    // b[]
                }
            }
            else
            {
            }
        }
    }
}