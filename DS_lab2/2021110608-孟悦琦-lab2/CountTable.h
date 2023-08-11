//
// Created by 孟繁兴 on 2022/10/11.
//

#ifndef DS_LAB2_COUNTTABLE_H
#define DS_LAB2_COUNTTABLE_H

#include <iostream>
#include <fstream>
#include <string>

typedef struct {
    char c;
    int cnt;
}cnt_of_word;

class CountTable {
private:
    // 核心列表，储存字符出现的频数
    cnt_of_word cnt_table[0x80-0x0A];
    // 列表长度
    int len = 0x80-0x0A;

public:CountTable();
    int getlen() const;
    int getcnt(int i) const;
    void readtext(std::string name);
    void printTable();

};



#endif //DS_LAB2_COUNTTABLE_H
