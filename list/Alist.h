//
// Created by Meng on 2022/9/7.
//

#ifndef LIST_ALIST_H
#define LIST_ALIST_H

#define maxlen 100



template <typename T> 
class Alist {
private:T elem[maxlen];
    int last;

public:Alist(int len);
    void print();
    void insert(T x,int position);
    int next(int position);
    int previous(int position);
    T retrieve(int position);
    void Delete(int position);
    int locate(T x);
    void makeNull();

};

// 打印函数，遍历线性表，进行打印
template <typename T> 
void Alist<T>::print() {
    for (int i = 0; i <= last; i++){
        std::cout << elem[i] << "\t";
    }
    std::cout << std::endl;
}

// 比较函数，用于比较两项是否相等，若相等反回1，不等返回0
template <typename T>
int equal(T x,T y){
    if(x == y){
        return 1;
    } else {
        return 0;
    }
}

// 读取函数，用于将输入的值读取到数组中
template <typename T>
void read(int position, T* a){
    std::cin >> a[position];
}


// 构造函数
template <typename T>
Alist<T>::Alist(int len) {
    if(len > maxlen || len <= 0){
        std::cout << "This number is not available!" << std::endl;
    } else {
        last = len-1;
        for (int i = 0; i < len; ++i) {
            read(i,elem);
        }
    }
}

// 查找位于某位置的元素，并返回这个元素的值
template <typename T> 
T Alist<T>::retrieve(int position) {
    if(position < 0 || position > last){
        // 输出位置不合法的提示信息，并返回空值
        std::cerr << "This position is not available!" << std::endl;
        return NULL;
    } else {
        return elem[position];
    }
}

// 找到线性表中某位置的下一个位置
template <typename T> 
int Alist<T>::next(int position) {
    if(position >= last || position < 0){
        return  -1; // 返回-1说明查找的位置无定义
    } else {
        return position+1;
    }
}

// 找到线性表中某位置的上一个位置
template <typename T> 
int Alist<T>::previous(int position) {
    if(position <= 0 || position > last){
        return -1; // 返回-1说明查找的位置无定义
    } else {
        return position-1;
    }
}

// 向线性表里插入一个元素
template <typename T> 
void Alist<T>::insert(T x, int position) {
    // 插入的位置从0开始，到尾位置结束
    if(position > last+1 || position < 0){
        std::cout << "This position is not available!" << std::endl;
    } else {
        for (int i = last; i >= position ; --i) {
            elem[i+1] = elem[i];
        }
        elem[position] = x;
        last += 1;
    }
}

// 删除线性表里的一个元素
template <typename T> 
void Alist<T>::Delete(int position) {
    if (position > last || position < 0){
        std::cout << "This position is illegal!" << std::endl;
    } else {
        for (int i = position; i < last; ++i) {
            elem[i] = elem[i+1];
        }
        last = last-1;
    }
}

// 查找只为某个定值的元素的位置，如果有多个则返回第一个
template <typename T> 
int Alist<T>::locate(T x) {
    for (int i = 0; i < last; ++i) {
        if (equal(x,elem[i])){
            return i;
        }
    }
    return -1; // 如果没找到该元素，则返回-1
}

// 将此表置为一个空表
template <typename T> 
void Alist<T>::makeNull() {
    last = 0;
}

#endif //LIST_ALIST_H
