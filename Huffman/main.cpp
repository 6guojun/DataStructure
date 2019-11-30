#include "Encode.h"
#include "Decode.h"

//参数说明
//argc没有输入是默认为1
int main(int argc, char *argv[])
{
    //Encode("Huffman\\New\\Test.txt");
    //Decode("Encode.txt");

    cout << "使用解密时请注意务必将Huffman.Tree和Huffman.Code文件放在本目录下。" << endl;
    cout << "使用加密时将在本目录下自动生成Huffman.Tree和Huffman.Code文件。" << endl;
    cout << "这回就不是调试级别了！！！" << endl;

    int s;
    for (int i = 1; i < argc; i++)
    {
        cout << "你输入了文件" << argv[i] << endl;
        cout << "请问执行什么操作(加密_输入0/解密_输入1):";
        cin >> s;
        if (s == 0)
        {
            Encode(argv[i]);
        }
        else if (s == 1)
        {
            Decode(argv[i]);
        }
    }

    return 0;
}