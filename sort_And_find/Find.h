//
// Created by Meng on 2022/11/6.
//

#ifndef SORT_AND_FIND_FINDUTILL_H
#define SORT_AND_FIND_FINDUTILL_H


// 查找工具类
class Find{
public:int BinSearch(int *a, int low, int up, int val);// 折半查找法，注意只能用在已经排序好的数组上，返回数据所在的数组下标
int find_time(int *a, int low, int up, int val);
};


#endif //SORT_AND_FIND_FINDUTILL_H
