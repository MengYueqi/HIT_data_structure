//
// Created by Meng on 2022/9/14.
//

#ifndef stack_STAKEL_H
#define stack_STAKEL_H

#include <iostream>
//typedef int Elemtype;

template <typename T>
struct node{
    T val;
    node *next;
};

template <typename T>
class stackL {
private:node<T> *list = nullptr;

public:stackL();
    void push(T x);
    void print();
    bool isempty();
    void pop();
    T top();
};

// 创造一个栈
template <typename T>
stackL<T>::stackL() {
//    由于是使用前驱节点的指针代表节点位置，头节点不存数据，故将头节点先设置为0，这里先构造出头节点，头节点不存储数据
    list = new node<T>;
    list->val = 0;
    list->next = nullptr;
}

// 将一个元素压入栈中
template <typename T>
void stackL<T>::push(T x) {
    node<T>* p;
    p = new node<T>;
    p->val = x;
    p->next = list->next;
    list->next = p;
}

// 打印一个栈，从栈顶打印
template <typename T>
void stackL<T>::print() {
    node<T> *p;
    p = list;
    while (p->next != nullptr){
        std::cout << p->next->val << "\t";
        p = p->next;
    }
    std::cout << std::endl;
}

// 检查栈是否为空
template <typename T>
bool stackL<T>::isempty() {
    return list->next == nullptr ? 1 : 0;
}

// 弹出栈的一个元素
template <typename T>
void stackL<T>::pop() {
    node<T> *p;
    if (isempty()) {
        std::cout << "This stack is empty!" << std::endl;
    } else {
        p = list->next;
        list->next = list->next->next;
        delete p;
    }
}

// 返回栈顶元素
template <typename T>
T stackL<T>::top(){return list->next->val;}

#endif //stack_STAKEL_H
