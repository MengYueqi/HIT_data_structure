//
// Created by Meng on 2022/9/25.
//

#ifndef STRING_STRING_H
#define STRING_STRING_H

#include <iostream>

int BFsearch(std::string target,std::string source); // 从source中查找targe
void print(std::string s,int begin,int len); //字符串打印函数
int* next(std::string s); // 预处理函数
int KMPsearch_core(std::string target,std::string source,int *next);
int KMPsearch(std::string target,std::string source); // KMP算法


#endif //STRING_STRING_H
