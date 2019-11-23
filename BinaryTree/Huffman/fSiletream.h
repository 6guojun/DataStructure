#pragma once

#include <iostream>
#include <fstream> // 读写文件的头文件
#include <string>
using namespace std;

//Define the max size of huffman tree.
//Actually we can only use such size if as key.
//128*2-1
#define ByteSize 128
#define MAXSIZE ByteSize * 2 - 1

void WriteFile(string filename, string append)
{
    ofstream ofs;
    ofs.open(filename, ios::app);
    // 4 写内容
    ofs << append << endl;

    // 5 关闭文件
    ofs.close();
}
void ReadFileWeight(string filename, int *&Weight)
{
    //Creat a heap of weight table.
    Weight = new int[ByteSize];
    for (int i = 0; i < ByteSize; i++)
    {
        Weight[i] = 0;
    }

    //Creat a file stream object & OPen the file.
    ifstream ifs;
    ifs.open(filename, ios::in);

    //Logic judge.
    if (!ifs.is_open())
    {
        cout << "File open failed.(Please check it is exist?)" << endl;
        return;
    }

    //Creat the weight table.
    char c;
    while ((c = ifs.get()) != EOF)
    {
        Weight[c]++;
    }

    //Close the file stream.
    ifs.close();
}