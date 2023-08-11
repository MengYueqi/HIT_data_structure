//
// Created by Meng on 2022/9/20.
//

#ifndef QUEUE_QUEUEL_H
#define QUEUE_QUEUEL_H

#include <iostream>


// TODO:运用模版类，重写队列存储结构
typedef int Elemtype;

// 队列的链表实现
template <typename T>
struct node{
    T val; // 内部所含的数值
    node *next;
};

template <typename T>
class Queuel {
private:node<T> *queue;
    node<T> *last;

public:Queuel();
    T front();
    void enqueue(T x);
    void print();
    T dequeue();
};

// 队列的构造函数
template <typename T>
Queuel<T>::Queuel() {
    queue = new node<T>;
    queue->next = nullptr;
    last = queue;
    std::cout << "This queue has created!" << std::endl;
}

// 返回队列的队首元素
template <typename T>
T Queuel<T>::front() {
    if (queue->next == nullptr){
        std::cout << "This queue is empty!" << std::endl;
        return -1; // 如果没有元素，则返回-1
    } else {
        return queue->next->val;
    }
}

// 向队列中添加一个元素
template <typename T>
void Queuel<T>::enqueue(T x) {
    node<T> *p = new node<T>;
    p->val = x;
    p->next = nullptr;
    last->next = p;
    last = last->next;
}

// 打印队列
template <typename T>
void Queuel<T>::print() {
    node<T> *p;
    p = queue;
    while (p->next != nullptr){
        std::cout << p->next->val << "\t";
        p = p->next;
    }
    std::cout << std::endl;
}

// 使队首元素出队
template <typename T>
T Queuel<T>::dequeue() {
    if (queue->next == nullptr){
        std::cout << "This queue is empty!" << std::endl;
        return -1;
    } else {
        node<T> *p;
        T ret;
        p = queue->next;
        queue->next = queue->next->next;
        ret = p->val;
        delete p;
        return ret;
    }
}

#endif //QUEUE_QUEUEL_H
