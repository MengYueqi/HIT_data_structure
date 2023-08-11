//
// Created by Meng on 2022/10/17.
//

#ifndef GRAPH_GRAPHLINK_H
#define GRAPH_GRAPHLINK_H

#define V_NUMBER 10
#include <iostream>
#include <fstream>
#include <queue>
#include <stack>

typedef struct node {
    int vertex; // 边上的顶点下标
    int cost; // 边上的权值
    node *next;
} EdgeNode;

typedef struct {
    EdgeNode *firstedge; // 指向第一个节点
    int identifier;
} VertexNode;

// TODO:添加最短路径算法，以及最小生成树算法
class GraphLink {
private:VertexNode vertex_list[V_NUMBER];
    void DFS1_core(const int i = 0);
    int visit[V_NUMBER] = {0};
    void BFS2_core(int i);
    void reset();
    int n = 0; // 遍历编号辅助变量

public:GraphLink();
    void print();
    void add_edge(int i,int j,int cost=1);
    node* getfirstedge(int i);
    void DFS1();
    void BFS1();
    void DFS2();
    void BFS2();
    int degree(int i);
    int getIdentifer(int i);
    void sequence();
};


#endif //GRAPH_GRAPHLINK_H
