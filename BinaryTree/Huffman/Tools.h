#pragma once

//Define the max size of huffman tree.
//Actually we can only use such size if as key.
//128*2-1
#define ByteSize 128
#define MAXSIZE ByteSize * 2 - 1

int CompressWeightTable(int *RawWeight, int *&Weight, char *&Character)
{
    int count = 0, i;
    Weight = new int[ByteSize];
    Character = new char[ByteSize];
    for (int i = 0; i < ByteSize; i++)
    {
        Weight[i] = 0;
    }
    for (i = 0; i < ByteSize; i++)
    {
        if (RawWeight[i] != 0)
        {
            Character[count] = i;
            Weight[count++]++;
        }
    }

    return count;
}