#include <iostream>
#include "MazeMartix.h"
#include "BlockStack.h"

using namespace std;

//文件名
#define FILENAME "Maze.txt"

int main()
{
    //定义矩阵
    vector<vector<int>> Maze = File2Martix(FILENAME);

    //展示迷宫
    DisplayMaze(Maze);

    //走迷宫
    BlockStak MazeStep;
    Init(MazeStep, Maze.size() * Maze[0].size());

    Block start = {1, 1, 0};
    Block end = {8, 9, 0};

    Push(Maze, MazeStep, start);

    Block CurB;
    Block NextStep;
    cout << "Start walking the maze." << endl;
    do
    {
        CurB = MazeStep.Step[MazeStep.StepNum - 1];

        if (CurB.direction > 3)
        {
            Pop(Maze, MazeStep);
            continue;
        }

        NextStep = Move(CurB, CurB.direction);
        cout << "The next step is:\t" << NextStep.X << '\t' << NextStep.Y << endl;

        if (IsCurrent(Maze, NextStep))
        {
            Push(Maze, MazeStep, NextStep);
        }
        else
        {
            MazeStep.Step[MazeStep.StepNum - 1].direction++;
        }
        getchar();
        DisplayMaze(Maze);
    } while (CurB.X != end.X || CurB.Y != CurB.Y);

    DisplayMaze(Maze);

    return 0;
}