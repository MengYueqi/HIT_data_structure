//
// Created by 孟繁兴 on 2022/10/17.
//

#ifndef GRAPH_GRAPHMATRIX_H
#define GRAPH_GRAPHMATRIX_H

#define V_NUMBER 10
#include <fstream>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>


class GraphMatrix {
private:int edge [V_NUMBER][V_NUMBER] = {0};
    int visit[V_NUMBER] = {0};
    //// 编号数组，这里用改写edge数组，运用结构的方式实现更合适，之后进行改进
    int number[V_NUMBER] = {0};
    void DFS1_core(const int i = 0);
    void BFS2_core(int i);
    void reset();
    int n = 0;

public:GraphMatrix(const char *name = nullptr);
    void print();
    bool isEdge(int i, int j);
    int getcost(int i,int j);
    void add_edge(int i,int j,int cost=1);
    void DFS1();
    void DFS2();
    void BFS1();
    void BFS2();
    int degree(int i);
    int getnumber(int i);
};


#endif //GRAPH_GRAPHMATRIX_H
