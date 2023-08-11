//
// Created by Meng on 2022/11/6.
//

#ifndef SORT_AND_FIND_BSTTREE_H
#define SORT_AND_FIND_BSTTREE_H

#include <iostream>
#include "BSTNode.h"


class BSTTree {
private:
    int find_min(BSTNode *&node);
    BSTNode *root = nullptr; // 根节点指针
public:BSTTree();
    BSTTree(int *a,int size);
    void insert(int val,BSTNode *&node);
    void traverse();
    BSTNode *find(int val);
    int find_time(int val);
    void delete_node(int val,BSTNode *&node);
    BSTNode *&getroot();

};


#endif //SORT_AND_FIND_BSTTREE_H
