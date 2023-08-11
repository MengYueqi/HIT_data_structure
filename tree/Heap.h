//
// Created by Meng on 2022/10/6.
// 关于最大堆的实现及算法，最小堆有着相似的原理
//

// TODO:可以用比较函数compare，来区分最大堆、最小堆
#ifndef TREE_HEAP_H
#define TREE_HEAP_H

#include <iostream>
#include <algorithm>
#define MaxSize 100

template<typename T>
class Heap {
private:T elem[MaxSize];
    int last=0; // 第0个元素不存放数值，这是为了满足父子之间 /2 向下取整的关系
    void swap(int a,int b);

public:Heap(int n=5);
    bool empty() const;
    bool full() const;
    void insert(T const &t);
    void print() const;
    T maxHeap() const;
    void deleteMax();
};

// 交换堆中的两个元素
template<typename T>
void Heap<T>::swap(int a, int b) {
    T temp;
    temp = elem[a];
    elem[a] = elem[b];
    elem[b] = temp;
}

// 堆的构造函数
template<typename T>
Heap<T>::Heap(int n) {
    last = n;
    std::cout << "Please input: " << std::endl;
    if(n>=MaxSize || n<0){
        std::cout << "This number is illegal!";
    }
    else {
        for (int i = 1; i < n + 1; ++i) {
            std::cout << "Please input the " << i << " number:" << std::endl;
            std::cin >> elem[i];
        }
        std::sort(elem+1,elem+last+1,std::greater<T>());
    }
    return;
}

// 判断堆是否为空
template<typename T>
bool Heap<T>::empty() const {
    return !last;
}

// 判断堆是否满
template<typename T>
bool Heap<T>::full() const {
    return (last == MaxSize-1);
}

// 向堆里插入一个元素
template<typename T>
void Heap<T>::insert(T const &t) {
    if (!full()){
        last++;
        elem[last] = t;
        int n = last;
        while (n){
            if (elem[n]>elem[n/2] && n>1){
                swap(n,n/2);
                n /= 2;
            } else {
                break;
            }
        }
    } else {
        std::cout << "This heap is full!" << std::endl;
        return;
    }
}

// 打印堆的元素，从堆顶开始顺序打印
template<typename T>
void Heap<T>::print() const {
    for (int i = 1; i < last+1; ++i) {
        std::cout << elem[i] << "\t";
    }
    std::cout << std::endl;
}

// 找堆中最大的元素
template<typename T>
T Heap<T>::maxHeap() const {
    return elem[0];
}

// 删除堆中的最大元素
template<typename T>
void Heap<T>::deleteMax() {
    int locate=1;
    elem[1] = elem[last--];
    while (locate <= last) {
        if (locate*2 <= last && elem[locate*2] > elem[locate*2+1]) {
            swap(locate*2,locate);
            locate = locate*2;
        } else if(locate*2+1 <= last){
            swap(locate*2+1,locate);
            locate = locate*2 + 1;
        } else {break;}
    }
}

#endif //TREE_HEAP_H
