//
// Created by Meng on 2022/9/12.
//

#ifndef LIST_LINKEDLIST_H
#define LIST_LINKEDLIST_H

#include <iostream>

// 链表接点结构体定义
template <typename T>
struct node{
    T val;
    node<T> *next;
};

// 链表类定义
template <typename T>
class Linkedlist {
private:node<T> *list;

public:Linkedlist();
    void print();
    void Delete(T x);
    node<T> *retrieve(int n);
    node<T> *previous(node<T> *p);
    node<T> *next(node<T> *p);
    void head_insert(T x);
    int locate(T x);
};

// 构造一个链表
template <typename T>
Linkedlist<T>::Linkedlist() {
    // 一个有头接点的链表
    list = new node<T>;
    list->next = nullptr;
}

// 打印一个链表
template <typename T>
void Linkedlist<T>::print() {
    node<T> *p = list;
    p = list->next;
    int cnt = 1;
    while (p != nullptr){
        std::cout << p->val << "\t";
        cnt ++;
        p = p->next;
    }
    std::cout << std::endl;
}

// 删除链表中存储的是某定值的元素
template <typename T>
void Linkedlist<T>::Delete(T x){
    // p为暂时存储的指针，q为遍历指针
    node<T> *p,*q;
    q = list;
    while (q->next != nullptr){
        if (q->next->val == x) {
            p = q->next->next;
            delete q->next;
            q->next = p;
            continue;
        }
        q = q->next;
    }
}

// 获取第n个位置的接点指针
template <typename T>
node<T> *Linkedlist<T>::retrieve(int n){
    node<T> *p = list;
    for (int i = 0; i < n; i++){
        p = p->next;
        // 若所找的位置超过链表长度，则返回空指针
        if (p->next == nullptr) {return nullptr;}
    }
    return p->next;
}

// 找到前导结点
template <typename T>
node<T> *Linkedlist<T>::previous(node<T> *p){
    node<T> *q = list;
    while (q != nullptr){
        if (q->next == p){
            return q;
        } else {
            q = q->next;
        }
    }
    return nullptr;
}

// 在链表头部插入一个元素
template <typename T>
void Linkedlist<T>::head_insert(T x){
    node<T> *p = new node<T>;
    p->next = list->next;
    list->next = p;
    list->next->val = x;
} 

// 在链表中查找某一个特定的值，并返回所在的链表中首个的位置
template <typename T>
int Linkedlist<T>::locate(T x) {
    int cnt = 0;
    node<T> *p = list;
    while (p->next){
        if (p->next->val == x){
            return cnt;
        } else {
            cnt ++;
            p = p->next;
        }
    }
    std::cout << "Do not have this value in the list!" << std::endl; 
    return -1;
}

// 在链表中找到某个元素的下一个元素，若没有则返回nullptr
template <typename T>
node<T> *Linkedlist<T>::next(node<T> *p){return p->next;}

#endif //LIST_LINKEDLIST_H
