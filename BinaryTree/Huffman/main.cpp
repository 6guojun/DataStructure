#include "Huyffman.h"
#include "fSiletream.h"

HuffmanTree HT;
HuffmanCode HC;

int main(int argc, char *argv[])
{
    string FileName = "C:\\Users\\EasternDay\\Desktop\\test.txt";
    //Logic judge.
    /*
    if (argc == 1)
    {
        return 0;
    }
    */

    //Get the file.
    for (int i = 1; i < argc; i++)
    {
        cout << "Input" << argv[i] << endl;
        FileName = argv[i];
    }

    HuffmanEncoder(HT, HC, FileName, "C:\\Users\\EasternDay\\Desktop\\123.txt");
    HuffmanDecoder(HT, HC, "C:\\Users\\EasternDay\\Desktop\\123.txt", "C:\\Users\\EasternDay\\Desktop\\1235.txt");

    return 0;
}