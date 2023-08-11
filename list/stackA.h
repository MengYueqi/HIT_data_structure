//
// Created by Meng on 2022/9/14.
//

#ifndef STAKE_STAKEA_H
#define STAKE_STAKEA_H

// 设置最多容纳100个元素
#define maxlen 100
#include <iostream>

template <typename T> class stackA {
    T elem[maxlen];
    int last = -1;

public:stackA();
    void push(const T& x);
    bool isempty();
    T top();
    void print() const;
    void pop();
};

// 栈的构造函数
template <typename T> stackA<T>::stackA(){}

// 将x压入栈
template <typename T> void stackA<T>::push(const T& x) {
    if (last >= maxlen-1){
        std::cout << "The stake is full!" << std::endl;
    } else {
        last += 1;
        elem[last] = x;
    }
}

// 判断栈是否为空
template <typename T> bool stackA<T>::isempty() {
    return !(last >= 0);
}

// 弹出栈中的一个元素
template <typename T> void stackA<T>::pop() {
    if (isempty()){
        std::cout << "This stake is empty!" << std::endl;
    } else {
        last -= 1;
    }
}

// 返回栈顶的元素
template <typename T> T stackA<T>::top() {
    return elem[last];
}

// 从栈底开始，打印栈的元素
template <typename T> void stackA<T>::print() const {
    for (int i = 0; i < last+1; ++i) {
        std::cout << elem[i] << "\t";
    }
    std::cout << std::endl;
}


#endif //STAKE_STAKEA_H
