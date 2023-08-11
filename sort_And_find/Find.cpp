//
// Created by Meng on 2022/11/6.
//

#include "Find.h"

// 折半查找法，注意只能用在已经排序好的数组上，返回数据所在的数组下标
int Find::BinSearch(int *a, int low, int up, int val) {
    int mid;
    if (low > up) {
        return -1; // 返回-1代表查找失败
    } else {
        mid = (low + up) / 2;
        if (val < a[mid]) {
            return BinSearch(a,low,mid-1,val);
        } else if (val > a[mid]) {
            return BinSearch(a,mid+1,up,val);
        } else {
            return mid;
        }
    }
}

// 计算折半查找某个元素的查找长度
int Find::find_time(int *a, int low, int up, int val) {
    int mid;
    if (low > up) {
        return 0; 
    } else {
        mid = (low + up) / 2;
        if (val < a[mid]) {
            return 1+find_time(a,low,mid-1,val);
        } else if (val > a[mid]) {
            return 1+find_time(a,mid+1,up,val);
        } else {
            return 1;
        }
    }
}
