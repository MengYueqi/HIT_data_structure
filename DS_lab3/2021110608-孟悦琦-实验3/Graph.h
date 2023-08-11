//
// Created by 孟繁兴 on 2022/10/28.
//

#ifndef DS_LAB3_GRAPH_H
#define DS_LAB3_GRAPH_H

#define V_NUMBER 10
#define inf 13904789

#include <iostream>
#include <fstream>
#include <stack>

class Graph {
private:int edge[V_NUMBER][V_NUMBER] = {0}; // 图的邻接矩阵
// dijkstra算法的辅助记录
int visit[V_NUMBER] = {0}; // 是否访问过的记录数组
int distance[V_NUMBER] = {0}; // dijkstra算法最短路径辅助数组
int pass[V_NUMBER] = {0}; // dijkstra算法路径辅助数组
// Floyd_Warshall算法的辅助记录
int P[V_NUMBER][V_NUMBER]; // Floyd_Warshall算法路径辅助数组
int D[V_NUMBER][V_NUMBER]; // Floyd_Warshall算法最短路径辅助数组
int dijkstra_chooseMin(int i);
void dijkstra_print_path(int i, int j);
void Floyd_Warshall_path(int i,int j);
void Print_FW_Single(int i);
void Floyd_Warshall_core();

public:Graph(const char *name = nullptr);
void printGraph();
void dijkstra(int i);
void Floyd_Warshall();
void find_single(int i);
void find_pair(int i,int j);
};


#endif //DS_LAB3_GRAPH_H
