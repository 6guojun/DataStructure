#pragma once
#include <iostream>
using namespace std;

#define MAXVERTEX 100                             //图的最大顶点数
#define INFINITY (1 << (sizeof(int) * 8 - 1) - 1) //用有符号的int最大值表示无穷大

typedef char vertextype; //定义定点的存储信息为字符型
typedef int arctype;     //定义边的权值为int型

//图的邻接矩阵的存储结构
typedef struct
{
    vertextype Vertex[MAXVERTEX];      //顶点表
    arctype Arc[MAXVERTEX][MAXVERTEX]; //邻接矩阵
    int Vertexnum;                     //图的当前顶点数
    int Arcnum;                        //图的当前边数
} MGraph;

//创建无向网
void CreateMGraph(MGraph &G)
{
    //输入顶点数目
    cout << "输入顶点数目:";
    cin >> G.Vertexnum;

    //合法性检查
    if (G.Vertexnum > MAXVERTEX)
    {
        cout << "节点数目太多，不方便给你整。" << endl;
        exit(0);
    }
    if (G.Vertexnum <= 0)
    {
        cout << "节点数目不太对，不给你整。" << endl;
        exit(0);
    }

    G.Arcnum = 0;

    //输入顶点信息
    cout << "输入顶点标号（除#外一切符号）:";
    for (int i = 0; i < G.Vertexnum; i++)
    {
        cin >> G.Vertex[i];
    }

    //表格初始化
    for (int i = 0; i < G.Vertexnum; i++) //将所有边初始化为无穷大
    {
        for (int j = 0; j < G.Vertexnum; j++)
        {
            G.Arc[i][j] = INFINITY; //值最大化
        }
    }

    cout << "输入边信息：" << endl;
    cout << "起始点 结束点 权值" << endl;
    //连接边
    char flag;
    int i, j, w;
    while (true)
    {
        cin >> flag;
        if (flag == '#')
        {
            return;
        }
        cin >> i >> j >> w;
        G.Arc[i][j] = w; //赋权
        G.Arcnum++;      //边数增加
    }
}

//打印邻接矩阵
void PrintfMGraph(MGraph G)
{
    cout << '\t';
    for (int i = 0; i < G.Vertexnum; i++)
    {
        cout << G.Vertex[i] << '\t';
    }
    cout << endl;
    for (int i = 0; i < G.Vertexnum; i++)
    {
        cout << G.Vertex[i] << '\t';
        for (int j = 0; j < G.Vertexnum; j++)
        {
            if (G.Arc[i][j] == INFINITY)
            {
                cout << '#' << '\t';
            }
            else
            {

                cout << G.Arc[i][j] << '\t';
            }
        }
        cout << endl;
    }
}

//深度搜索(递归)
void DFS_Rec(MGraph G, int i, bool *Visited)
{
    Visited[i] = true;   //设置为遍历过
    cout << G.Vertex[i]; //输出
    for (int j = 0; j < G.Vertexnum; j++)
    {
        if (G.Arc[i][j] != INFINITY && !Visited[j])
        {
            DFS_Rec(G, j, Visited);
        }
    }
}

//深度遍历最小生成树
void DFSTraveser(MGraph G)
{
    bool *Visited = new bool[G.Vertexnum];
    for (int i = 0; i < G.Vertexnum; i++)
    {
        if (!Visited[i])
        {
            DFS_Rec(G, i, Visited);
            cout << endl;
        }
    }
}