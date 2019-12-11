#include "AdjacencyMatrix.h"

MGraph G;

/**
 * 5个结点
 * ABCDE
 * @ 0 1 5
 * @ 1 2 6
 * @ 1 3 8
 * @ 2 3 7
 * @ 0 4 9
 * @ 3 4 10
 * #
*/

int main()
{
    CreateMGraph(G); //初始化
    PrintfMGraph(G); //打印

    DFSTraveser(G);
    return 0;
}