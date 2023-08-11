//
// Created by Meng on 2022/9/25.
//

#include "String.h"

// 从source中寻找target，并返回起始位置，如果没找到，则返回-1
int BFsearch(std::string target,std::string source){
    int i,j;
    i = j = 0;
    while (i != source.length() && j != target.length()){
        if (source[i] == target[j]) {
            i++;j++;
        } else {
            i = i-j+1;
            j = 0;
        }
    }
    if (j == target.length()) { return i-j; }
    else { return -1; }
}

// 打印一个字符串，从begin开始打印，打印长度len
void print(std::string s,int begin,int len){
    if (begin == -1){
        std::cout << "Do not find string!" << std::endl;
    } else {
        std::cout << "The string is from the " << begin << " to " << begin+len << std::endl;
        for (int i = begin; i < begin+len; ++i) {
            std::cout << s[i];
        }
        std::cout << std::endl;
    }
}

// 预处理函数，判断字符串的滑动量
int* next(std::string s){
    int *ret = new int[s.length()];
    int i,j;
    for (i = 0; i < s.length(); ++i) {
        if (i == 0) { ret[i] = -1; }
        else {
            for (j = i; j >= 0 ; --j) {
                int cnt = 0;
                bool flag = true;
                for (int k = i-j+1; k <= i; ++k) {
                    if (s[k] != s[cnt]) {flag = false;}
                    cnt ++;
                }
                if (flag) {
                    ret[i] = j-1;
                    break;
                }
            }
            if (j == -1){
                ret[i] = 0;
            }
        }
    }
    return ret;
}

// KMP匹配算法的核心算法
int KMPsearch_core(std::string target,std::string source,int *next){
    int i,j;
    i = j = 0;
    while (i != source.length() && j != target.length()){
        if (source[i] == target[j]) {
            i++;j++;
        } else {
            if (next[j] == -1) { i=i-j+1;j=0; }
            else { j=next[j]; }
        }
    }
    if (j == target.length()) { return i-j; }
    else { return -1; }
}

// KMP算法
int KMPsearch(std::string target,std::string source){
    // 创建偏移量数组
    int* next_array = next(target);
    // 调用核心算法
    return KMPsearch_core(target,source,next_array);
}