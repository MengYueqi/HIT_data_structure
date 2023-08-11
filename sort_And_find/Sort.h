//
// Created by Meng on 2022/11/6.
//

#ifndef SORT_H
#define SORT_H

#pragma once

#include <iostream>
#include <vector>
#include <queue>

class Sort{
public:
    Sort(int chose = 1); // chose可以设置为1或-1，1为从小到大排序，-1为从大到小排序，默认为1
    ~Sort();
    void insert(int *a,int size); // 插入排序
    void select(int *a,int size); // 选择排序
    void bubble(int *a,int size); // 选择排序
    void shell(int *a,int size,std::vector<int> lens); // 希尔排序
    void quick(int *a,int lo,int hi); // 快速排序
    void radix(int *a,int size); // 基数排序
    void heap(int *a,int size); // 堆排序
    void merge(int *a,int size); // 二路归并排序

private:
    int (*compare) (int,int); // 本类的比较函数
    void insert_position(int *a,int position,int end,int len=1); // 在数组中的某个位置插入数值
    void swap(int *a,int i,int j); // 交换位置的函数
    int maxbit(int *a,int size); // 求一个数组内数的最大位数
    void pushDown(int *a,int size,int num); // 堆排序中的下推辅助函数
    void mergeSort(int *a,int low,int high); // 归并排序的核心函数
    void Merge(int *a,int low,int mid,int high); // 归并函数
};

int compare1(int a,int b);
int compare2(int a,int b);

#endif