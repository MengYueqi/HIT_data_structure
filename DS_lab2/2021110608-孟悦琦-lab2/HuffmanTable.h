//
// Created by 孟繁兴 on 2022/10/11.
//

#ifndef DS_LAB2_HUFFMANTABLE_H
#define DS_LAB2_HUFFMANTABLE_H

#include "HuffmanTree.h"
#include "CountTable.h"
#include <fstream>

std::string CHARTO16STR(unsigned char c);

typedef struct {
    char c;
    std::string code;
} Huffcode;

typedef struct {
    std::string _01code;
    std::string _16code;
} encodeTable;


class HuffmanTable {
private:Huffcode HuffTable[0x80-0x0A];
    void setcode(int n);
    // 储存编码的辅助栈s
    std::stack<char> s;
    // 全译表
    encodeTable full[16] = {"0000","0",
                            "0001","1",
                            "0010","2",
                            "0011","3",
                            "0100","4",
                            "0101","5",
                            "0110","6",
                            "0111","7",
                            "1000","8",
                            "1001","9",
                            "1010","a",
                            "1011","b",
                            "1100","c",
                            "1101","d",
                            "1110","e",
                            "1111","f"};

    // 缺省时的译码表
    encodeTable lack[14] = {"0","0",
                            "1","1",
                            "10","2",
                            "11","3",
                            "00","0",
                            "01","1",
                            "000","0",
                            "001","1",
                            "010","2",
                            "011","3",
                            "100","4",
                            "101","5",
                            "110","6",
                            "111","7"};

public:void update_HFTable(HuffmanTree HFTree);
    void printTable();
    std::string encode(std::string name);
    std::string decode(std::string name);

};


#endif //DS_LAB2_HUFFMANTABLE_H
