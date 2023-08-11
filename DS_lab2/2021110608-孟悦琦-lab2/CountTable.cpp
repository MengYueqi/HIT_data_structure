//
// Created by 孟繁兴 on 2022/10/11.
//

#include "CountTable.h"

// 构造一个CountTable
CountTable::CountTable() {
    // 使用可以打印的字符为例，但由于\n的存在，把数据集扩大0x16的容量，扩展到0x80-0x0A
    for (int i = 0; i < 0x80-0x0A; ++i) {
        cnt_table[i].c = (char)0x0A+i;
        cnt_table[i].cnt = 0;
    }
//    // 测试数据
//    cnt_table[0].cnt = 19;
//    cnt_table[1].cnt = 10;
//    cnt_table[2].cnt = 3;
//    cnt_table[3].cnt = 29;
}

// 返回频数列表的长度
int CountTable::getlen() const {
    return len;
}

// 返回第i个数的频次
int CountTable::getcnt(int i) const {
    return cnt_table[i].cnt;
}

// 读取数据并设置频数表的函数
void CountTable::readtext(std::string name) {
    // 创建流对象
    std::ifstream ifs;
    ifs.open(name,std::ios::out);

    char c;
    while ((c=ifs.get()) != EOF) {
        if (c<=0x80 && c>=0x0A) {
            cnt_table[c-0x0A].cnt += 1; // 如果数据合法，对频数加一
        }
    }

    // 关闭文件
    ifs.close();
}

// 打印CountTable
void CountTable::printTable() {
    for (int i = 0; i < 0x80 - 0x0A; ++i) {
        std::cout << cnt_table[i].c << "\t" << cnt_table[i].cnt << std::endl;
    }
}