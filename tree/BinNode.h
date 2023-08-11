//
// Created by Meng on 2022/9/28.
//

#ifndef TREE_BINNODE_H
#define TREE_BINNODE_H

#include <iostream>
#include <stack>
#include <queue>

template<typename T>
class BinTree;

// TODO:添加一个父亲指针，对之后后续遍历算法进行改写，并且增加红黑树flag
template<typename T>
class BinNode {
    friend class BinTree<T>; // BinTree作为BinNode的友元，这样直接访问BinNode中的元素
private:T val;
    BinNode<T> *lc,*rc,*parent;
    void preorder(); // 以某个节点为跟节点，进行先序遍历
    void inorder(); // 以某个节点为跟节点，进行中序遍历
    void postorder(); // 以某个节点为跟节点，进行后序遍历
    void preorderAlong(); // 先序遍历非递归形式
    void inorderAlong(); // 中序遍历非递归形式
    void postorderAlong(); // 后序遍历非递归形式
    void levelorder(); // 从某个节点开始，进行层序遍历
    bool iscomplete(); // 从某个节点开始，判断以此节点为跟节点的树是否为完全二叉树
    int maxwide(); // 从某个节点开始，判断以此节点为跟节点的子树最大宽度（各层节点的最大值）
};

// 后序遍历非递归算法中的辅助结点
template <typename T> struct postNode{
    BinNode<T> *binNode;
    bool isVisit;
};

// 先序遍历递归形式
template <typename T>
void BinNode<T>::preorder() {
    if (this != nullptr) {
        std::cout << this->val << "\t";
        this->lc->preorder();
        this->rc->preorder();
    }
}

// 中序遍历递归形式
template<typename T>
void BinNode<T>::inorder() {
    if (this != nullptr) {
        this->lc->inorder();
        std::cout << this->val << "\t";
        this->rc->inorder();
    }
}

// 后续遍历递归形式
template<typename T>
void BinNode<T>::postorder() {
    if (this != nullptr){
        this->lc->postorder();
        this->rc->preorder();
        std::cout << this->val << "\t";
    }
}

// 先序遍历非递归形式
template<typename T>
void BinNode<T>::preorderAlong() {
    std::stack<BinNode<T> *> s;
    BinNode<T> *t;
    t = this;
    while (true) {
        while (t){
            std::cout << t->val << "\t";
            s.push(t->rc);
            t = t->lc;
        }
        if(s.empty()) {break;}
        else{
            t = s.top();
            s.pop();
        }
    }
}

// 中序遍历非递归形式
template<typename T>
void BinNode<T>::inorderAlong() {
    std::stack<BinNode<T> *> s;
    BinNode<T> *t;
    t = this;
    while (true) {
        while (t) {
            s.push(t);
            t = t->lc;
        }
        if(s.empty()){break;}
        else {
            t = s.top();
            s.pop();
            std::cout << t->val << "\t";
            t = t->rc;
        }
    }
}

// 层序遍历非递归形式
template<typename T>
void BinNode<T>::levelorder() {
    std::queue<BinNode<T> *> q;
    BinNode<T> *t;
    q.push(this);
    while (!q.empty()) {
        t = q.front();
        q.pop();
        std::cout << t->val << "\t";
        if (t->lc) {q.push(t->lc);}
        if (t->rc) {q.push(t->rc);}
    }
}

// 判断一棵树是否是完全二叉树
template<typename T>
bool BinNode<T>::iscomplete() {
    // 默认为0,是完全二叉树
    int flag = 0;
    bool ret = 1;
    std::queue<BinNode<T> *> q;
    BinNode<T> *t;
    q.push(this);
    while (!q.empty()) {
        t = q.front();
        q.pop();
        if (t) {
            if (flag == 1){
                ret = 0;
                std::cout << ">> "<< t->val << " <<" << "\t";
            } else {std::cout << t->val << "\t";}
        }
        if (t) {
            q.push(t->lc);
            q.push(t->rc);
        }
        if (t == nullptr) {
            std::cout << '#' << "\t";
            // flag置为1,此树为完全二叉树
            flag = 1;
        }
    }
    return ret;
}

// 判断二叉树的最大宽度
template<typename T>
int BinNode<T>::maxwide() {
    std::queue<BinNode<T> *> q;
    q.push(this);
    int width,Maxwidth;
    Maxwidth = 0;
    width = q.size();
    while (!q.empty()) {
        Maxwidth = Maxwidth < width ? width : Maxwidth;
        for (int i = 0; i < width; ++i) {
            BinNode<T> *t = q.front();
            if (t->rc) {q.push(t->rc);}
            if (t->lc) {q.push(t->lc);}
            q.pop();
        }
        width = q.size();
    }
    std::cout << "The max width is " << Maxwidth << std::endl;
    return Maxwidth;
}

// 后序遍历非递归形式
template<typename T>
void BinNode<T>::postorderAlong() {
    std::stack<postNode<T>> s;
    // 创建辅助结构体
    postNode<T> p;
    p.binNode = this;
    p.isVisit = false;
    while (true) {
        // 深入到树的最左下
        while (p.binNode && p.isVisit==false) {
            s.push(p);
            p.binNode = p.binNode->lc;
        }
        if(s.empty()){break;}
        else {
            p = s.top();
            // 若结点未被访问过，则先访问其右子树
            if (p.isVisit == false) {
                s.pop();
                p.isVisit = true; // 将此结点标记为已经访问过一次
                s.push(p);
                p.binNode = p.binNode->rc;
                p.isVisit = false;
                continue;
            // 若已经访问过一次，则直接访问此结点
            } else {
                std::cout << p.binNode->val << "\t";
                s.pop();
            }
        }
    }

}

#endif //TREE_BINNODE_H
