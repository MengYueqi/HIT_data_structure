//
// Created by Meng on 2022/11/6.
//

#include <iostream>
#include "BSTTree.h"
#include "Find.h"
#include <stdlib.h>
#include "Sort.h"
#include <cstring>

// TODO: 这部分要增加的东西比较多，要增加AVL树、B（B+）树、红黑树、伸展树
#define SIZE 1024 // 设定数组大小的宏常量

void random_array(int *a,int size); // 打乱一个size大小的数组
void swap(int *a,int i,int j); // 交换数组中的两个位置

int main() {
    // 创建源数据
    std::cout << "Hello,WOrld" << std::endl;
    int a[SIZE],b[SIZE]; // 两个源数组
    for (int i = 0; i < SIZE; ++i) {
        a[i] = 2*i+1;
    }
    memcpy(b,a,SIZE*sizeof(int));
    random_array(b,SIZE);

    // 创建两个BST树
    BSTTree tree1 = BSTTree(a,SIZE);
    BSTTree tree2 = BSTTree(b,SIZE);

    // 统计平均查找长度
    float ASL1,ASL2;
    ASL1 = ASL2 = 0;
    // 计算成功的平均查找长度
    for (int i = 0; i < SIZE; i++)
    {
        ASL1 += tree1.find_time(2*i+1);
        ASL2 += tree2.find_time(2*i+1);
    }
    ASL1 /= SIZE;
    ASL2 /= SIZE;
    std::cout << "SUCCESS:" << std::endl;
    std::cout << "The first tree ASL is : " << ASL1 << std::endl;
    std::cout << "The second tree ASL is : " << ASL2 << std::endl; 
    
    // 计算失败的平均查找长度
    ASL1 = ASL2 = 0;
    for (int i = 0; i < SIZE; i++)
    {
        ASL1 += tree1.find_time(2*i+2);
        ASL2 += tree2.find_time(2*i+2);
    }
    ASL1 /= SIZE;
    ASL2 /= SIZE;
    std::cout << "FAIL:" << std::endl;
    std::cout << "The first tree ASL is : " << ASL1 << std::endl;
    std::cout << "The second tree ASL is : " << ASL2 << std::endl; 

    // 计算折半查找的平均查找长度
    float ASL = 0;
    Find f;
    
    // 计算成功的平均查找长度
    for (int i = 0; i < SIZE; i++)
    {
        ASL += f.find_time(a,0,1023,2*i+1);
    }
    ASL /= SIZE;
    std::cout << "SUCCESS:" << std::endl;
    std::cout << "The ASL is : " << ASL << std::endl;
    
    // 计算失败的平均查找长度
    ASL = 0;
    for (int i = 0; i < SIZE; i++)
    {
        ASL += f.find_time(a,0,1023,2*i);
    }
    ASL /= SIZE;
    std::cout << "FAIL:" << std::endl;
    std::cout << "The ASL is : " << ASL << std::endl;

    std::vector<int> vec;
    vec.push_back(2);
    vec.push_back(1);
    int al[] = {0,9,8,4,2};
    Sort sort = Sort(1);
    sort.merge(b,SIZE);
    for (int i = 0; i < 100; i++){
        std::cout << b[i] << "\t";
    }
}

// 交换数组中两个元素的位置的函数
void swap(int *a,int i,int j) {
    int temp;
    temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

// 在数组内进行随机交换
void random_array(int *a,int size) {
    for (int i = 0; i < size; ++i) {
        int rand_idx = i + rand() % (size - i);
        swap(a,i,rand_idx);
    }
}
