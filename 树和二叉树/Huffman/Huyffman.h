#include <iostream>
#include <stack>

using namespace std;

//Define the max size of huffman tree.
//Actually we can only use such size if as key.
//128*2-1
#define ByteSize 128
#define MAXSIZE ByteSize * 2 - 1

//Define the element type which include weight information.
typedef struct
{
    int weight;
    int parent;
    int leftChild;
    int rightChild;
} WeightInformation;

//Define the huffman tree type.
typedef struct
{
    WeightInformation Elem[MAXSIZE];
    int num, root;
} HuffmanTree;

typedef struct
{
    char Character;
    char *Code;
} HuffmanEncode;
//Defined
typedef struct
{
    HuffmanEncode *Coding;
    int num;
} HuffmanCode;

void FindMin_2(HuffmanTree HT, int &min_1, int &min_2);                                          //Find the min 2 & return the count size.
void CreateHuffmanTree(HuffmanTree &HT, HuffmanCode &HC, int *Weight, char *Character, int num); //How 2 creat a huffman tree.
void DisplayHuffmanTree(HuffmanTree HT);                                                         //Show a huffman tree.
void DisplayHuffmanCode(HuffmanCode HC);                                                         //Show a huffman code.

//How 2 creat a huffman tree.
void CreateHuffmanTree(HuffmanTree &HT, HuffmanCode &HC, int *Weight, char *Character, int num)
{
    //Loop controller.
    int i, j;

    //Copy weiight to huffman tree.
    HT.num = num;
    for (i = 0; i < num; i++)
    {
        HT.Elem[i] = {Weight[i], -1, -1, -1};
    }
    cout << "Huffman tree init successfullt!" << endl;

    //  Find the 2 min position.
    int min_1_pos, min_2_pos;
    for (i = 0; i < num - 1; i++)
    {
        FindMin_2(HT, min_1_pos, min_2_pos);
        //Union 2 one.
        HT.Elem[HT.num] = {HT.Elem[min_1_pos].weight + HT.Elem[min_2_pos].weight, -1, min_1_pos, min_2_pos};
        HT.Elem[min_1_pos].parent = HT.Elem[min_2_pos].parent = HT.num++;
    }
    cout << "Huffman tree creat successfullt!" << endl;

    //Creat huffmancode.
    HC.num = num;
    stack<int> ReverseCode;
    WeightInformation WI;
    int pla, count;
    HC.Coding = new HuffmanEncode[num];
    for (i = 0; i < num; i++)
    {
        HC.Coding[i].Character = Character[i];
        WI = HT.Elem[i];
        pla = i;
        while (WI.parent != -1)
        {
            if (HT.Elem[WI.parent].leftChild == pla)
            {
                ReverseCode.push(0);
            }
            else
            {
                ReverseCode.push(1);
            }
            pla = WI.parent;
            WI = HT.Elem[pla];
        }
        //Creat huffman coding table.
        HC.Coding[i].Code = new char[ReverseCode.size() + 1];
        count = ReverseCode.size();
        for (j = 0; j < count; j++)
        {
            HC.Coding[i].Code[j] = '0' + ReverseCode.top();
            ReverseCode.pop();
        }
        HC.Coding[i].Code[j] = '\0';
    }
    //cout << "Huffman tree creat successfullt!" << endl;
}

//To find the min of the vector.
void FindMin_2(HuffmanTree HT, int &min_1, int &min_2)
{
    int m1, m2, num;
    min_1 = min_2 = m1 = m2 = 0;

    //For each element in huffman tree.
    for (int i = 0; i < HT.num; i++)
    {
        //If this elem its father do not confirm(not well-defined) then continue.
        if (HT.Elem[i].parent != -1)
        {
            continue;
        }

        //Get the num of it.
        num = HT.Elem[i].weight;
        if (m2 != 0 && m1 != 0)
        {
            if (num < m1)
            {
                m2 = m1;
                min_2 = min_1;
                m1 = num;
                min_1 = i;
            }
            else if (num < m2)
            {
                m2 = num;
                min_2 = i;
            }
            continue;
        }
        if (m1 == 0)
        {
            m1 = num;
            min_1 = i;
            continue;
        }
        if (m2 == 0)
        {
            m2 = num;
            min_2 = i;
        }
        if (m2 < m1)
        {
            m2 += m1;
            m1 = m2 - m1;
            m2 -= m1;
            min_2 += min_1;
            min_1 = min_2 - min_1;
            min_2 -= min_1;
        }
    }
}

//Show huffman tree.
void DisplayHuffmanTree(HuffmanTree HT)
{
    for (int i = 0; i < HT.num; i++)
    {
        WeightInformation WT = HT.Elem[i];
        cout << WT.weight << "\t" << WT.parent << "\t" << WT.leftChild << "\t" << WT.rightChild << endl;
    }
}

void DisplayHuffmanCode(HuffmanCode HC)
{
    for (int i = 0; i < HC.num; i++)
    {
        cout << HC.Coding[i].Character << '\t' << HC.Coding[i].Code << endl;
    }
}