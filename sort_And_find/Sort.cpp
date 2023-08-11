//
// Created by Meng on 2022/11/6.
//

#include "Sort.h"

// 排序类的初始化函数
Sort::Sort(int chose)
{
    if(chose == 1){
        compare = compare1;
    } else if (chose == -1) {
        compare = compare2;
    } else {
        std::cerr << "Please chose 1 or -1" << std::endl;
    }
}

Sort::~Sort()
{

}

// 插入函数的具体实现
void Sort::insert(int *a,int size){
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if ((*compare)(a[j],a[i])){
                insert_position(a,j,i); // 将a[i]中存储的数据插入到j位置中
                break;
            }
        }
    }
}

// 插入辅助函数
void Sort::insert_position(int *a,int position,int end,int len){
    int t = a[end];
    for (int i = end-len; i >= position; i-=len)
    {
        a[i+len] = a[i];
    }
    a[position] = t;
}


// 选择排序的主要函数部分
void Sort::select(int *a,int size){
    int position;
    for (int i = 0; i < size; i++)
    {
        position = i;
        for (int j = i; j < size; j++)
        {
            if ((*compare)(a[position],a[j])){
                position = j;
            } 
        }
        swap(a,i,position);
    }
}

// 起泡排序的实现函数
void Sort::bubble(int *a,int size){
    for (int i = 0; i < size; i++)
    {
        for (int j = size-1; j >= i; j--)
        {
            if((*compare)(a[j],a[j+1])){
                swap(a,j,j+1);
            }
        }
    }
}

// 希尔排序的实现函数
void Sort::shell(int *a,int size,std::vector<int> lens){
    // 对输入步长向量进行入口审查
    // 禁止输入0个步长
    if(lens.size() < 1){
        std::cerr << "Please input correct lens!" << std::endl;
        return;
    }
    // 禁止前步长小于后步长
    for (int i = 0; i < lens.size()-1; i++){
        if (lens[i] < lens[i+1])
        {
            std::cerr << "Please input correct lens!" << std::endl;
            return;
        }
    }
    // 强制最后的步长为1
    if (lens[lens.size()-1] != 1){
        std::cerr << "The last number must be 1!" << std::endl;
        return;
    }

    // 希尔排序的核心内容
    for (int j = 0; j < lens.size(); j++){
        for (int k = lens[j]; k < size; k++){
            for (int l = k; l>=lens[j]; l-=lens[j]){
                if ((*compare)(a[l-lens[j]],a[k])){
                    insert_position(a,l-lens[j],k,lens[j]);
                }
            }
        }
    }
}

// 基本快速排序的函数实现
void Sort::quick(int *a,int lo,int hi){
    if (lo >= hi){return;}
    int i = lo+1;
    int j = hi;
    while (true){
        while (!(*compare)(a[i],a[lo])){ // 当a[i]小于等于a[lo]时
            i++;
            if(i == hi){break;}
        }
        while (!(*compare)(a[lo],a[j])){ // 当a[j]大于等于a[lo]时 
            j--;
            if(j == lo){break;}
        }
        if (i >= j){break;}
        swap(a,i,j);
    }
    swap(a,lo,j);
    quick(a,lo,j-1);
    quick(a,j+1,hi);
}

// 基数排序的实现函数
void Sort::radix(int *a,int size){
    int m = maxbit(a,size); // 求出需要进行排序的次数
    std::queue<int> data; // 数据的辅助队列
    std::queue<int> q[10]; // 基数排序的辅助队列
    // 将排序的数组转移到队列中
    for (int i = 0; i < size; i++){
        data.push(a[i]);
    }

    // 基数排序
    int num; // 确定数据所在的桶
    for (int i = 0; i < m; i++){
        while(!data.empty()){
            num = data.front();
            for (int k = 0; k < i; k++){num /= 10;}
            num %= 10;
            q[num].push(data.front());
            data.pop();
        }
        
        for (int k = 0; k < 10; k++){ // 转移到辅助队列
               while (!q[k].empty()){
                    data.push(q[k].front());
                    q[k].pop();
               }
        }
    }

    // 将辅助数组中排好序的数转移到原数组中
    for (int i = 0; i < size; i++){
        a[i] = data.front();
        data.pop();
    }
}

// 堆排序的实现函数
void Sort::heap(int *a,int size){
    for (int i = (size/2)-1; i >= 0; i--){
        pushDown(a,size,i); 
    }
    
    // 取最大堆的首元素放在堆后，并维护一个最大堆
    int max;
    for (int i = size-1; i >= 0; i--)
    {
        max = a[0];
        a[0] = a[i];
        a[i] = max;
        pushDown(a,i,0);
    }
}

// 归并排序的函数实现
void Sort::merge(int *a,int size){
    mergeSort(a,0,size-1);
}

// 归并排序的核心函数
void Sort::mergeSort(int *a,int low,int high){
    int mid = (high+low)/2;
    if(low < high){
        mergeSort(a,low,mid);
        mergeSort(a,mid+1,high);
        Merge(a,low,mid,high);
    }
}

// 交换位置的函数
void Sort::swap(int *a,int i,int j){
    int temp;
    temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

// 堆排序的下推辅助函数
void Sort::pushDown(int *a,int size,int num){
    size -= 1; // 更改为数组的对应下标
    
    // 下推的具体实现步骤
    while (num*2+1 < size){
        // 对仅有一个叶节点的进行特殊处理
        if (num*2+1 == size){
            if ((*compare)(a[num*2+1],a[num])){
                swap(a,num,num*2+1);
                break;
            }
        } else {
            if ((*compare)(a[num*2+1],a[num]) || (*compare)(a[num*2+2],a[num])){
                if ((*compare)(a[num*2+1],a[num*2+2])){
                    swap(a,num*2+1,num);
                    num = num*2+1;
                } else {
                    swap(a,num*2+2,num);
                    num = num*2+2;
                }
            } else {
                break;
            }
        }
    }
}

// 求一个数组内数的最大位数
int Sort::maxbit(int *a,int size){
    int maxbit,bit;
    maxbit = 1;
    for (int i = 0; i < size; i++){
        int p = 10;
        bit = 1;
        while (a[i] >= p){
            p *= 10;
            bit++;
        }
        if (bit > maxbit){
            maxbit = bit;
        }
    }
    return maxbit;
}

// 归并函数
void Sort::Merge(int *a,int low,int mid,int high){
    // 创建中间数组aux
    int aux[high+1];
    for (int i = low; i <= high; i++){
        aux[i] = a[i];
    }
    
    int i,j,k;
    i = low;
    j = mid+1;
    k = low;
    // 选择两个归并段中较小的数，转移到数组中
    while (i<=mid && j<=high){
        a[k++] = (aux[i]<=aux[j]) ? aux[i++] : aux[j++];
    }
    // 转移剩余部分
    while (i <= mid){
        a[k++] = aux[i++];
    }
    while (j <= high){
        a[k++] = aux[j++];
    }
}

// 比较函数(严格比较)
int compare1(int a,int b){return a>b;}
int compare2(int a,int b){return a<b;}