//
// Created by Meng on 2022/11/6.
//

#include "BSTNode.h"


// 以某一个跟节点开始，中序遍历一棵BST树
void BSTNode::traverse() {
    if (this != nullptr) {
        this->lchild->traverse();
        std::cout << this->val << "\t";
        this->rchild->traverse();
    }
}

// 以某个节点开始，查找其子树中的某个节点，如果存在，就返回那个节点的指针，如果不存在，返回nullptr
BSTNode *BSTNode::find(int val) {
    if (this == nullptr || this->val == val) {
        return this;
    } else if (val > this->val){
        this->rchild->find(val);
    } else if (val < this->val) {
        this->rchild->find(val);
    }
}

// 计算从某个节点开始，查找某个值的查找长度
int BSTNode::find_time(int val) {
    if (this == nullptr) { // 如果是空指针，实际上并没有进行比较
        return 0;
    } else if(this->val == val) {
        return 1;
    } else if (val > this->val) {
        return 1 + this->rchild->find_time(val);
    } else {
        return 1 + this->lchild->find_time(val);
    }
}


