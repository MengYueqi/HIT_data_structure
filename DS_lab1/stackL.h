//
// Created by 孟繁兴 on 2022/9/14.
//

#ifndef STAKE_STAKEL_H
#define STAKE_STAKEL_H

#include <iostream>

template<typename T>
struct node{
    T val;
    node *next;
};

template<typename T>
class stackL {
private:node<T> *list = nullptr;

public:stackL();
    void push(T const &x);
    T top() const;
    void print() const;
    bool empty() const;
    void pop();
    void makeNull();

};

// 创造一个栈
template<typename T>
stackL<T>::stackL() {
//    由于是使用前驱节点的指针代表节点位置，头节点不存数据，故将头节点先设置为0，这里先构造出头节点，头节点不存储数据
    list = new node<T>;
    list->next = nullptr;
}

// 将一个元素压入栈中
template<typename T>
void stackL<T>::push(T const &x) {
    node<T>* p;
    p = new node<T>;
    p->val = x;
    p->next = list->next;
    list->next = p;
}

// 返回栈顶元素
template<typename T>
T stackL<T>::top() const {
    return list->next->val;
}

// 打印一个栈，从栈顶打印
template<typename T>
void stackL<T>::print() const{
    node<T> *p;
    p = list;
    while (p->next != nullptr){
        std::cout << p->next->val << "\t";
        p = p->next;
    }
    std::cout << std::endl;
}

// 检查栈是否为空
template<typename T>
bool stackL<T>::empty() const {
    return list->next == nullptr ? 1 : 0;
}

// 弹出栈的一个元素
template<typename T>
void stackL<T>::pop() {
    node<T> *p;
    if (empty()) {
        std::cout << "This stake is empty!" << std::endl;
    } else {
        p = list->next;
        list->next = list->next->next;
        delete p;
    }
}

template<typename T>
void stackL<T>::makeNull() {
    while (!empty()) {
        pop();
    }
}

#endif //STAKE_STAKEL_H
