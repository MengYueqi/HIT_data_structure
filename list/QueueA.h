//
// Created by Meng on 2022/9/21.
//

#ifndef QUEUE_QUEUEA_H
#define QUEUE_QUEUEA_H

#define maxlen 5
#include <iostream>

typedef int Elemtype;

template <typename T>
class QueueA {
private:T queue[maxlen];
    int first; // 队列中第一个元素的位置
    int last; // 队列中的最后一个元素
    bool isfull;
    bool isempty;

public:QueueA();
    void enqueue(T x);
    void print();
    void dequeue();
    T front();

};

// 构造一个队列
template <typename T>
QueueA<T>::QueueA() {
    first = 0;
    last = -1;
    isempty = true;
    isfull = false;
}

// 向队尾增加一个元素
template <typename T>
void QueueA<T>::enqueue(T x) {
    if (isfull){
        std::cout << "This queue is full!" << std::endl;
    } else {
        isempty = false;
        if (last == maxlen-1) {
            last = 0;
            queue[last] = x;
        } else {
            last += 1;
            queue[last] = x;
        }
    }
    if ((last == maxlen-1 && first == 0) || (last+1 == first)) {
        isfull = true;
    }
    return;
}

// 打印这个队列，从队首到队尾
template <typename T>
void QueueA<T>::print() {
    if (isempty) {
        std::cout << "This queue is empty!" << std::endl;
    } else {
        if (last > first) {
            for (int i = first; i < last+1; ++i) {
                std::cout << queue[i] << "\t";
            }
        } else {
            for (int i = first; i < maxlen; ++i) {
                std::cout << queue[i] << "\t";
            }
            for (int i = 0; i < last+1; ++i) {
                std::cout << queue[i] << "\t";
            }
        }
        std::cout << std::endl;
    }
}

// 从队首释放一个元素
template <typename T>
void QueueA<T>::dequeue() {
    if (isempty) {
        std::cout << "This queue is empty!" << std::endl;
    } else {
        if (first == maxlen-1) {
            first = 0;
        } else {
            first += 1;
        }
        isfull = false;
    }
    if ((first == last+1) || (first == 0 && last == maxlen-1)) {
        isempty = true;
        // 重置队列
        first = 0;
        last = -1;
    }
}

// 获取队列中的第一个元素
template <typename T>
T QueueA<T>::front(){
    if (isempty){
        std::cout << "This queue is empty!" << std::endl;
        return NULL;
    } else {
        return queue[first];
    }
}


#endif //QUEUE_QUEUEA_H
