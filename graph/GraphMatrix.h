//
// Created by Meng on 2022/10/17.
//

#ifndef GRAPH_GRAPHMATRIX_H
#define GRAPH_GRAPHMATRIX_H

#define V_NUMBER 10
#define inf 1232144

#include <fstream>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>

// 创建边结构体
typedef struct edge{
    int begin;
    int end;
    int len;
} Edge;

class GraphMatrix {
private:int edge [V_NUMBER][V_NUMBER] = {0};
    int visit[V_NUMBER] = {0};
    int number[V_NUMBER] = {0};
    // dijkstra算法的辅助记录
    int distance[V_NUMBER] = {0}; // dijkstra算法最短路径辅助数组
    int pass[V_NUMBER] = {0}; // dijkstra算法路径辅助数组
    // Floyd_Warshall算法的辅助记录
    int P[V_NUMBER][V_NUMBER]; // Floyd_Warshall算法路径辅助数组
    int D[V_NUMBER][V_NUMBER]; // Floyd_Warshall算法最短路径辅助数组
    void DFS1_core(const int i = 0);
    void BFS2_core(int i);
    void reset();
    int dijkstra_chooseMin(int i);
    void dijkstra_print_path(int i,int j);
    void Floyd_Warshall_path(int i,int j);
    void Floyd_Warshall_core();
    void Sort(Edge* edges,int lo,int hi);
    void swapEdge(Edge* edges,int i,int j);
    int Find(int *father,int i);
    int n = 0;

public:GraphMatrix();
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
    void sequence();
    void dijkstra(int i);
    void Floyd_Warshall();
    void Prim();
    void kruskal();
};


#endif //GRAPH_GRAPHMATRIX_H
