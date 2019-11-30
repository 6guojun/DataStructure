#pragma once

#include "HuffmanCode.h"

void Decode(const char FileName[])
{
    //输入文件
    ifstream ifs;
    ifs.open(FileName, ios::in);

    //逻辑检查
    if (!ifs.is_open())
    {
        cout << "文件打开失败！" << endl; //报错
        system("pause");                  //暂停
        exit(0);                          //退出
    }

    int Plus; //补0位数
    Plus = ifs.get() - '0';

    int count = 8; //循环位移计数

    string decoding = ""; //解密生字符串

    char c, temp;
    while (ifs.get(c))
    {
        //位移获取
        while (count-- != 0)
        {
            temp = c >> count;
            decoding += (temp & 1) + '0';
        }
        count = 8;
    }

    //关闭文件
    ifs.close();

    HuffmanTree HT = ReadHuffmanTree("Huffman.Tree");
    HuffmanCode HC = ReadHuffmanCode("Huffman.Code");

    //输出文件
    ofstream ofs;
    ofs.open("Decode.txt", ios::trunc);

    //逻辑检查
    if (!ofs.is_open())
    {
        cout << "文件创建失败！" << endl; //报错
        system("pause");                  //暂停
        exit(0);                          //退出
    }

    //循环变量
    temp = HT.root - 1;
    for (int i = 0; i < decoding.length() - Plus; i++)
    {
        if (decoding[i] == '0')
        {
            temp = HT.Elem[temp].leftChild;
        }
        else
        {
            temp = HT.Elem[temp].rightChild;
        }
        if (HT.Elem[temp].leftChild == -1)
        {
            ofs << HC.Coding[temp].Character;
            temp = HT.root - 1;
        }
    }

    //关闭文件
    cout << endl;

    ofs.close();

    cout << "输入文件\t解密\t成功" << endl;
}