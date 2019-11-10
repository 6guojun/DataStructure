#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

//返回一个二维数组矩阵（地图矩阵）
vector<vector<int>>
File2Martix(string Filename)
{
    //文件流
    ifstream File(Filename, ios::in);

    //数据定义
    string AnyLine;             //行文本
    vector<vector<int>> Matrix; // 地图矩阵

    //按行读取
    while (getline(File, AnyLine))
    {
        //打印整行字符串
        //cout << AnyLine << endl;

        //存成二维表结构
        stringstream Line(AnyLine); //文本流
        string Block;
        vector<int> LineArray;
        //按照空格分隔
        while (getline(Line, Block, ' '))
        {
            //stoi(s,p,b)	把字符串s从p开始转换成b进制的int
            LineArray.push_back(stoi(Block, 0, 10)); //将每个整数存储进去
        }
        Matrix.push_back(LineArray); //每一行vector数据都放到Matrix中去
    }

    return Matrix;
}

//显示迷宫矩阵
void DisplayMaze(vector<vector<int>> MazeMartix)
{
    //输出结果
    cout << "You entered such a maze:" << endl;
    cout << "## ";
    for (int k = 0; k < MazeMartix[0].size(); k++)
    {
        cout << k << " ";
    }
    cout << endl;
    cout << "##";
    for (int k = 0; k < MazeMartix[0].size(); k++)
    {
        cout << "##";
    }
    cout << endl;
    for (int i = 0; i < MazeMartix.size(); i++)
    {
        cout << i << "# ";
        for (int j = 0; j < MazeMartix[i].size(); j++)
            cout << MazeMartix[i][j] << " ";
        cout << endl;
    }
}