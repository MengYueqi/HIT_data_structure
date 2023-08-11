//
// Created by Meng on 2022/11/6.
//

#ifndef SORT_AND_FIND_BSTNODE_H
#define SORT_AND_FIND_BSTNODE_H

#include <iostream>

class BSTNode {
friend class BSTTree; // 声明友元，以便在BSTNode中调用
private:int val;
    BSTNode *lchild;
    BSTNode *rchild;
//    BSTNode *parent; 父亲节点的指针，之后进行完善
    void traverse(); //// 看看是不是能通过传赋初值的参数来修改
    BSTNode *find(int val);
    int find_time(int val);


};


#endif //SORT_AND_FIND_BSTNODE_H
