#include "Huyffman.h"

int main()
{
    HuffmanTree HT;
    HuffmanCode HC;
    int WEIGHT[ByteSize] = {5, 29, 7, 8, 14, 23, 3, 11};
    char CHARACTER[ByteSize] = {65, 66, 67, 68, 69, 70, 71, 72};
    int NUM = 8;
    CreateHuffmanTree(HT, HC, WEIGHT, CHARACTER, NUM);
    //cout << HT.Elem[HT.num - 1].weight;
    cout << "Huffman Tree:" << endl;
    DisplayHuffmanTree(HT);

    cout << endl;

    cout << "Huffman Code:" << endl;
    DisplayHuffmanCode(HC);

    system("pause");
    return 0;
}