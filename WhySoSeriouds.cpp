//命名空间
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//宏定义
#define N 3  //选手数目
#define M 10 //评委评分数目

//全局变量
int add = N;
//sum 每个人的总成绩
int sum[N] = {0}, Max[N], Min[N];
float aver[N] = {0};

//结构体Player定义
struct player
{
    int num;
    char name[8];
    int score[M];
};

void Inistplayer(struct player[], int);   //初始化选手数组
void Inputscore(int[], int);              //输入分数
void sort(struct player[], float[], int); //排序

int main()
{
    //flag=1(选择<1-6>)，flag=0（选择<7.退出系统>）
    //n 选项的序号<1.输入选手数据/2.评委打分/3.成绩排序/4.数据查询/5.追加学生数据/6.写入数据文件/7.退出系统>
    int flag = 1, n, i, m, j;
    FILE *fp;                     //文件操作对象
    fp = fopen("data.txt", "w+"); //打开文件

    struct player a[20]; //最多包含二十个选手的数组

    //输出显示信息（显示在控制台的信息）
    printf("**********1.输入选手数据***********\n");
    printf("**********2.评委打分***************\n");
    printf("**********3.成绩排序***************\n");
    printf("**********4.数据查询***************\n");
    printf("**********5.追加学生数据***********\n");
    printf("**********6.写入数据文件***********\n");
    printf("**********7.退出系统***************\n");

    //falg判定是否退出（默认flag为1，当选择<7.退出系统>的时候flag变为0，则退出循环-退出程序）
    while (flag)
    {
        printf("你想进行的操作:"); //询问要干啥（控制台输出）
        scanf("%d", &n);           //输入操作的序号

        //根据选择项进行操作
        switch (n)
        {

        //选择<1.输入选手数据>
        case 1:
            //输入选手数据
            Inistplayer(a, N); //看到下面Inistplayer函数
            break;

        //选择<2.评委打分>
        case 2:
            srand((unsigned)time(NULL)); //生成随机数种子

            //因为三个选手，循环三次
            for (i = 0; i < N; i++)
            {
                printf("第%d位选手的分数:", i + 1); //播报第几个选手（控制台输出）
                Inputscore(a[i].score, M);          //输入成绩，查看下方Inputscore函数
                //输出成绩（显示出来看）
                for (j = 0; j < M; j++)
                    printf("%d ", a[i].score[j]);
                printf("\n"); //换行给下一个
            }
            break;

        //选择<3.成绩排序>
        case 3:
            //遍历每个选手
            for (i = 0; i < N; i++)
            {
                Max[i] = a[i].score[0]; //随便选一个最大值，不如就第一个元素吧
                Min[i] = a[i].score[0]; //随便选一个最小值，不如就第一个元素吧
                //遍历整个评分
                for (j = 0; j < M; j++)
                {
                    sum[i] += a[i].score[j]; //总分

                    if (Max[i] < a[i].score[j])
                        Max[i] = a[i].score[j]; //找最大

                    if (Min[i] > a[i].score[j])
                        Min[i] = a[i].score[j]; //找最小
                }

                //求平均分
                aver[i] = (float)(sum[i] - Max[i] - Min[i]) / (M - 2);
            }
            //选手排序
            sort(a, aver, N);
            //输出选手信息
            for (i = 0; i < N; i++)
                printf("%s %5.2f\n", a[i].name, aver[i]);
            break;

        //选择<4.数据查询>
        case 4:
            printf("你想查询选手的数据:"); //显示询问信息
            scanf("%d", &m);               //输入查询人员序号

            //查找三个选手
            for (i = 0; i < N; i++)
                //序号相同
                if (a[i].num == m)
                {
                    //输出信息
                    printf("%d号选手%s总分:%d,最高分%d,最低分%d,平均分%5.2f", a[i].num, a[i].name, sum[i], Max[i], Min[i], aver[i]);
                    printf("\n");
                }
            break;

        //选择<5.追加学生数据>
        case 5:
            printf("请输入要追加的选手数据：\n");
            scanf("%d %s", &a[add].num, &a[add].name);
            add++;
            break;

        //选择<6.写入数据文件>
        case 6:
            printf("将数据写入文件中：\n");
            for (i = 0; i < add; i++)
            {
                fprintf(fp, "%d ", a[i].num);
                fprintf(fp, "%s ", a[i].name);
                fprintf(fp, "%d\n", a[i].score);
            }
            break;

        //选特<7.退出系统>
        case 7:
            exit(0);
            break;
        default:
            flag = 0;
        }
    }
}

//初始化结构体
void Inistplayer(struct player a[], int n)
{
    for (int i = 0; i < n; i++)
        scanf("%d %s", &a[i].num, &a[i].name);
}

//输入分数
void Inputscore(int score[], int n)
{
    //根据选手成绩数目确定
    for (int i = 0; i < n; i++)
    {
        score[i] = 1 + (int)10 * rand() / (RAND_MAX + 1); //随机成绩
    }
}

//选手排序
void sort(struct player a[], float b[], int n)
{
    int i, k, j, t;
    float temp;
    char str[8];

    //遍历每个选手
    for (i = 0; i < n; i++)
    {
        k = i;
        for (j = i + 1; j < n; j++)
            if (b[k] > b[j])
                k = j;
        if (k != i)
        {
            //交换成绩
            temp = b[i];
            b[i] = b[k];
            b[k] = temp;

            //交换名字
            strcpy(str, a[i].name);
            strcpy(a[i].name, a[k].name);
            strcpy(a[k].name, str);

            //交换序号
            t = a[i].num;
            a[i].num = a[k].num;
            a[k].num = t;
        }
    }
}