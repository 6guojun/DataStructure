#pragma once
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

#define MAXVERTEX 100                             //图的最大顶点数
#define INFINITY (1 << (sizeof(int) * 8 - 1) - 1) //用有符号的int最大值表示无穷大

typedef char vertextype; //定义定点的存储信息为字符型
typedef int arctype;     //定义边的权值为int型

enum GraphType
{
    Graph,
    Diagraph
};

//图的邻接矩阵的存储结构
typedef struct
{
    vertextype Vertex[MAXVERTEX];      //顶点表
    arctype Arc[MAXVERTEX][MAXVERTEX]; //邻接矩阵
    int Vertexnum;                     //图的当前顶点数
    int Arcnum;                        //图的当前边数
    GraphType GT;                      //图类别
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

    cout << "输入图类别（0-无向图，1有向图）:" << endl;
    bool IsDiagraph;
    cin >> IsDiagraph;
    G.GT = IsDiagraph ? Diagraph : Graph;

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
    cout << "@ 起始点 结束点 权值 (#结束)" << endl;
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
        //无向图
        if (G.GT == Graph)
        {
            G.Arc[j][i] = w; //赋权
        }
        G.Arcnum++; //边数增加
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

//深度搜索（非递归）
void DFS(MGraph G, int v, bool *Visited)
{
    stack<int> Routes;
    Routes.push(v);
    Visited[v] = true;
    cout << G.Vertex[v];
    while (!Routes.empty())
    {
        int i = Routes.top(), j;
        for (j = 0; j < G.Vertexnum; j++)
        {
            if (G.Arc[i][j] != INFINITY && !Visited[j])
            {
                Routes.push(j);
                Visited[j] = true;
                cout << G.Vertex[j];
                break;
            }
        }
        if (j == G.Vertexnum)
        {
            Routes.pop();
        }
    }
}

//深度遍历最小生成树(0-非遍历，1-遍历)
void DFSTraveser(MGraph G, int Type)
{
    bool *Visited = new bool[G.Vertexnum];
    for (int i = 0; i < G.Vertexnum; i++)
    {
        if (!Visited[i])
        {
            Type ? DFS(G, i, Visited) : DFS_Rec(G, i, Visited);
            cout << endl;
        }
    }
}

//广度搜索
void BFSTraveser(MGraph G)
{
    queue<int> Routes;
    bool *Visited = new bool[G.Vertexnum];
    for (int v = 0; v < G.Vertexnum; v++)
    {
        if (!Visited[v])
        {
            cout << endl;
            Routes.push(v);
            cout << G.Vertex[v];
            Visited[v] = true;
        }
        while (!Routes.empty())
        {
            int i = Routes.front(), j;
            for (j = 0; j < G.Vertexnum; j++)
            {
                if (G.Arc[i][j] != INFINITY && !Visited[j])
                {
                    Routes.push(j);
                    Visited[j] = true;
                    cout << G.Vertex[j];
                }
            }
            Routes.pop();
        }
    }
}