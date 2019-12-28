#pragma once

#include "HuffmanCode.h"

void Encode(const char FileName[])
{
    //获取权值表
    WeightTable WT = ReadFileWeight(FileName);

    HuffmanTree HT = CreatHuffmanTree(WT);
    HuffmanCode HC = CreatHuffmanCode(HT, WT);

    //保存哈夫曼编码
    SaveHuffmanCode("Huffman.Code", HC);
    SaveHuffmanTree("Huffman.Tree", HT);

    //加密文件
    ofstream ofs;
    ofs.open("Encode.txt", ios::trunc);

    //逻辑检查
    if (!ofs.is_open())
    {
        cout << "文件保存失败！" << endl; //报错
        system("pause");                  //暂停
        exit(0);                          //退出
    }

    //读文件
    ifstream ifs;
    ifs.open(FileName, ios::in);

    //生字符串
    string encoding = "";

    //不断读取字符
    char c;
    while (ifs.get(c))
    {
        //寻找匹配
        for (int j = 0; j < HC.num; j++)
        {
            //找到匹配
            if (HC.Coding[j].Character == c)
            {
                //拼接
                encoding += HC.Coding[j].Code;
                break;
            }
        }
    }

    //关闭文件
    ifs.close();

    //补了多少个0
    int Plus = 0;
    //不为8的倍数，则补0
    while (encoding.length() % 8 != 0)
    {
        encoding += "0";
        Plus++;
    }

    //先输出补的0数目
    ofs << Plus;
    //位移字符
    c = 0;
    for (int i = 0; i <= encoding.length(); i++)
    {   
        //逢8进1
        if (i != 0 && i % 8 == 0)
        {
            //输出
            ofs << c;
            //重置
            c = 0;
        }
        //左移一位
        c = c << 1;
        c += encoding[i] - '0';
    }

    //关闭文件
    ofs.close();

    cout << "输入文件\t加密\t成功" << endl;
}