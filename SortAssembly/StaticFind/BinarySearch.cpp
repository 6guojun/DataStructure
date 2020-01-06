/**
 * 带哨兵的顺序查找
*/
#include <iostream>
#include <time.h>

using namespace std;

#define random(x) (rand() % x)

int Search(int t[], int n, int s);

int main()
{
    int Hello[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    cout << Search(Hello, 20, 101);

    return 0;
}

int Search(int t[], int n, int s)
{
    int low = 0, high = n - 1;
    int mid;
}