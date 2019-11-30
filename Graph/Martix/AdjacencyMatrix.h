#pragma once
#include <iostream>
using namespace std;

#define MAXVERTEX 100  //图的最大顶点数
#define INFINITY 32767 //用有符号的int最大值表示无穷大

enum GraphType
{
    Diagraph,
    Graph
};

typedef char vertextype; //定义定点的存储信息为字符型
typedef int arctype;     //定义边的权值为int型

//图的邻接矩阵的存储结构
typedef struct
{
    vertextype vertex[MAXVERTEX];      //顶点表
    arctype arc[MAXVERTEX][MAXVERTEX]; //邻接矩阵
    int vertexnum;                     //图的当前顶点数
    int arcnum;                        //图的当前边数
    GraphType GT;                      //图类型

} MGraph;

//创建无向网
void CreateMGraph(MGraph &G)
{
    cout << "输入顶点数目:";
    cin >> G.vertexnum; //输入顶点数目
    cout << "输入边数:";
    cin >> G.arcnum; //输入边数
    cout << "输入顶点标号:";
    for (int i = 0; i < G.vertexnum; i++) //输入顶点信息
    {
        cin >> G.vertex[i];
    }
    for (int i = 0; i < G.vertexnum; i++) //将所有边初始化为无穷大
        for (int j = 0; j < G.vertexnum; j++)
            G.arc[i][j] = INFINITY;
    for (int k = 0; k < G.arcnum; k++)
    {
        int i, j, w;
        cin >> i >> j; //输入构成边的两个顶点
        cin >> w;      //输入边所对应的权值
        G.arc[i][j] = w;
        G.arc[j][i] = G.arc[i][j]; //无向图的邻接矩阵为对称矩阵
    }
}

//打印邻接矩阵
void PrintfMGraph(MGraph G)
{
    for (int i = 0; i < G.vertexnum; i++)
    {
        for (int j = 0; j < G.vertexnum; j++)
            cout << G.arc[i][j] << '\t';
        cout << endl;
    }
}

//主函数
int main()
{
    MGraph G;
    CreateMGraph(G);
    PrintfMGraph(G);
    return 0;
}