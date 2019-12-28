#include "CommonSetting.h"

typedef struct
{
    int X;
    int Y;
    int direction;
} Block;

typedef struct
{
    Block *Step;
    int StepNum;
} BlockStak;

//初始化
Status Init(BlockStak &b, int size)
{
    b.StepNum = 0;
    b.Step = new Block[size];
    return DONE;
}

//压栈
Status Push(vector<vector<int>> &Maze, BlockStak &b, Block c)
{
    b.Step[b.StepNum].X = c.X;
    b.Step[b.StepNum].Y = c.Y;
    b.Step[b.StepNum].direction = 0;
    b.StepNum++;

    Maze[c.X][c.Y] = 2;

    return DONE;
}

//出栈
Status Pop(vector<vector<int>> &Maze,BlockStak &b)
{
    b.StepNum--;

    Maze[b.Step[b.StepNum].X][b.Step[b.StepNum].Y] = 3;
    return DONE;
}

//下一步
Block Move(Block b, int dir)
{
    switch (dir)
    {
    case 0:
        return Block{b.X+0, b.Y+1, 0};
    case 1:
        return Block{b.X+1, b.Y+0, 0};
    case 2:
        return Block{b.X+0, b.Y-1, 0};
    case 3:
        return Block{b.X-1, b.Y+0, 0};
    default:
        exit(0);
    }
}

//是否可通行
bool IsCurrent(vector<vector<int>> Maze, Block b)
{
    return Maze[b.X][b.Y] == 0;
}