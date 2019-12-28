#include "Encode.h"
#include "Decode.h"

//参数说明
//argc没有输入是默认为1
int main(int argc, char *argv[])
{
    //Encode("Huffman\\New\\Test.txt");
    //Decode("Encode.txt");

    cout << "Please prepare Huffman.Tree and Huffman.Code" << endl;
    cout << "We will creat Huffman.Tree and Huffman.Code if encode." << endl;

    int s;
    for (int i = 1; i < argc; i++)
    {
        cout << "Input file:" << argv[i] << endl;
        cout << "Excute(Encode0/Decode1):";
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