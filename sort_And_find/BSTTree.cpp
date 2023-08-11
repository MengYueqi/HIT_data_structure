//
// Created by Meng on 2022/11/6.
//

#include "BSTTree.h"

// 创建一棵新的BST树
BSTTree::BSTTree() {
    root = nullptr;
    int val = 0;
    while (true){
        std::cin >> val;
        if (val != -1) {
            insert(val, root);
        } else {
            break;
        }
    }
}

// 默认以跟节点为开始，在BST树上插入一个新的节点
void BSTTree::insert(int val,BSTNode *&node) {
    if (node == nullptr) {
        BSTNode *new_node = new BSTNode;
        new_node->val = val;
        new_node->lchild = nullptr;
        new_node->rchild = nullptr;
        node = new_node;
        return;
    } else if (val > node->val) {
        insert(val,node->rchild);
    } else if (val < node->val) {
        insert(val,node->lchild);
    } else {
        // 如有雷同，不予插入，并进行提示
        std::cout << "There is a same value in the BST-tree!" << std::endl;
        return;
    }
}

// 中序遍历一棵BST树
void BSTTree::traverse() {
    root->traverse();
    std::cout << std::endl;
}

// 在BST树中寻找某个值，没有则返回nullptr
BSTNode *BSTTree::find(int val) {return root->find(val);}

// 在以某个节点为跟节点的子树中，按值删除一个节点
void BSTTree::delete_node(int val,BSTNode *&node) {
    if (node->val < val) {
        delete_node(val,node->rchild);
    } else if (node->val > val) {
        delete_node(val,node->lchild);
    } else {
        if (node->rchild == nullptr) {
            BSTNode *temp = node; // 释放节点空间，左链继承。
            node = node->lchild;
            delete temp; // 释放节点空间，防止已经无用的节点占用空间
        } else if (node->lchild == nullptr) {
            BSTNode *temp = node; // 释放节点空间，右链继承。
            node = node->rchild;
            delete temp;
        } else {
            node->val = find_min(node->rchild); // 找到右链最小值，并且完成替换
        }
    }
}

// 找到右子树的一个最小节点
int BSTTree::find_min(BSTNode *&node) {
    int ret;
    // 找到最小节点，右链继承，并返回最小节点。
    if (node->lchild == nullptr) {
        ret = node->val;
        BSTNode *temp = node;
        node = node->rchild;
        delete temp;
        return ret;
    } else {
        return find_min(node->lchild);
    }
}

// 获取跟节点指针的函数
BSTNode *&BSTTree::getroot() {
    return root;
}

// 运用数组初始化BST树
BSTTree::BSTTree(int *a, int size) {
    for (int i = 0; i < size; ++i) {
        insert(a[i],root);
    }
}

// 计算查找某个元素的查找长度
int BSTTree::find_time(int val) {
    return root->find_time(val);
}
