//
// Created by Meng on 2022/9/27.
//

#ifndef TREE_BINTREE_H
#define TREE_BINTREE_H

#include <iostream>
#include "BinNode.h"

template<typename T>
class BinTree {
private: BinNode<T> *root;
    int height;

public:BinTree(BinNode<T> *parent = nullptr);
    BinNode<T>* getroot() const ; // 获取根节点
    void preorder() const; // 先序遍历法
    void inorder() const; // 中序遍历法
    void postorder() const; // 后序遍历算法
    void preorderAlong() const; // 先序遍历算法，迭代形式
    void inorderAlong() const; // 中序遍历算法，迭代形式
    void postorderAlong() const; // 后序遍历算法，迭代形式
    void levelorder() const; // 层序遍历算法
    bool iscomplete() const; // 判断此树是否是完全二叉树
    int maxwide() const; // 判断此树的最大宽度（各层节点的最大值）
};

template<typename T>
BinTree<T>::BinTree(BinNode<T> *parent) {
    T t;
    std::cin >> t;
    if (t == '#') {root = nullptr;}
    else {
        root = new BinNode<T>;
        root->val = t;
        root->parent = parent;
        root->lc = BinTree<T>(root).root;
        root->rc = BinTree<T>(root).root;
    }
}

template<typename T>
BinNode<T>* BinTree<T>::getroot() const {return root;}

template<typename T>
void BinTree<T>::preorder() const {root->preorder();std::cout << std::endl;}

template<typename T>
void BinTree<T>::inorder() const {root->inorder();std::cout << std::endl;}

template<typename T>
void BinTree<T>::postorder() const {root->postorder();std::cout << std::endl;}

template<typename T>
void BinTree<T>::preorderAlong() const {root->preorderAlong();std::cout << std::endl;}

template<typename T>
void BinTree<T>::inorderAlong() const {root->inorderAlong();std::cout << std::endl;}

template<typename T>
void BinTree<T>::levelorder() const {root->levelorder();std::cout << std::endl;}

template<typename T>
bool BinTree<T>::iscomplete() const {
    bool ret = root->iscomplete();
    std::cout << std::endl;
    return ret;
}

template<typename T>
int BinTree<T>::maxwide() const {
    return root->maxwide();
}

template<typename T>
void BinTree<T>::postorderAlong() const {root->postorderAlong();std::cout << std::endl;}

#endif //TREE_BINTREE_H
