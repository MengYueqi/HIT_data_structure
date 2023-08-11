//
// Created by 孟繁兴 on 2022/10/10.
//

#ifndef DS_LAB2_HUFFMANTREE_H
#define DS_LAB2_HUFFMANTREE_H

#include <iostream>
#include "CountTable.h"
#include <string>
#include <stack>


typedef struct {
    int weight;
    int parent;
    int lchild;
    int rchild;
}HTNODE;

class HuffmanTree {
private:HTNODE *HuffmanTree;
    int count; // HuffmanTree内含元素数
    int node1,node2;

public:void read_text();
    void creat_HFTree(CountTable CT);
    void select_min(int len);
    void print_Tree(); // 调试函数
    int getparent(int i) const;
    int getlchild(int i) const;
    int getrchild(int i) const;

};


#endif //DS_LAB2_HUFFMANTREE_H
