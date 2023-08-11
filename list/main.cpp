//
// Created by Meng on 2022/9/7.
//

#include <iostream>
#include "Linkedlist.h"

int main() {
    Linkedlist<int> list = Linkedlist<int>();
    list.head_insert(9);
    list.head_insert(7);
    list.head_insert(8);
    list.head_insert(8);
    list.head_insert(3);
    list.head_insert(4);
    list.head_insert(6);
    list.print();
    std::cout << list.next(list.retrieve(4))->val << std::endl;
}
