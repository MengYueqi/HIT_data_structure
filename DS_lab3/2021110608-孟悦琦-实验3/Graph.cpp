//
// Created by 孟繁兴 on 2022/10/28.
//

#include "Graph.h"

// 构造一个图
Graph::Graph(const char *name) {
    // 创建读取文件流
    std::ifstream ifs;
    ifs.open(name,std::ios::in);

    // 读取文件并初始化图
    int i,j,cost;
    i = j = cost = 0;
    if (ifs.is_open()) {
        while (!ifs.eof()) {
            ifs >> i >> j >> cost;
            edge[i][j] = cost;
        }
        ifs.close();
    } else {
        std::cerr << "Can't open the file!" << std::endl;
    }
}

// 打印一个图
void Graph::printGraph() {
    for (int i = 0; i < V_NUMBER; ++i) {
        for (int j = 0; j < V_NUMBER; ++j) {
            std::cout << edge[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

// dijkstra算法，找到目前距离最短的节点
int Graph::dijkstra_chooseMin(int i) {
    int min = i;
    for (int j = 0; j < V_NUMBER; ++j) {
        if (visit[j] == 0) {
            if (min == i) {
                min = j;
            } else {
                min = distance[min] < distance[j] ? min : j;
            }
        }
    }
    return min;
}

// 根据dijkstra算法的结结果，打印两个顶点之间的路
void Graph::dijkstra_print_path(int i, int j) {
    // 辅助栈s
    std::stack<int> s;
    int k = j;
    // 遍历获取路径
    while (k!=i) {
        s.push(k);
        k = pass[k];
    }

    // 打印路径的算法
    std::cout << "shortest distance: " << distance[j] << "\t";
    std::cout << "path: " << i << "\t";
    while (!s.empty()) {
        std::cout << s.top() << "\t";
        s.pop();
    }
    std::cout << std::endl;
}

// 运用dijkstra算法，找到从某一顶点开始，到其他顶点的最短路径
void Graph::dijkstra(int i) {
    // 算法预处理
    for (int j = 0; j < V_NUMBER; ++j) {
        if (edge[i][j] && i!=j) {
            distance[j] = edge[i][j];
        } else if (i!=j) {
            distance[j] = inf;
        }
    }
    for (int j = 0; j < V_NUMBER; ++j) {
        pass[j] = i;
    }
    visit[i] = 1;

    for (int j = 0; j < V_NUMBER; ++j) {
        int v = dijkstra_chooseMin(i);
        visit[v] = 1;
        for (int k = 0; k < V_NUMBER; ++k) {
            // 更新最短距离
            if (visit[k] == 0 && edge[v][k]) {
                // 如果加入新的边使之前的距离更短，就更新距离和走过的边
                if (distance[k] > distance[v]+edge[v][k]) {
                    distance[k] = distance[v]+edge[v][k];
                    pass[k] = v;
                }
            }
        }
    }

    // 打印路径
    for (int j = 0; j < V_NUMBER; ++j) {
        if (j!=i && distance[j] != inf) {
            dijkstra_print_path(i, j);
        } else if (j!=i){
            std::cout << "The path " << i << " to " << j << " :Not Find!" << std::endl;
        }
    }
}

// 运用Floyd_Warshall打印路径的算法
void Graph::Floyd_Warshall_path(int i, int j) {
    int k = P[i][j];
    if (k!=-1) {
        Floyd_Warshall_path(i,k);
        std::cout << k << "\t";
        Floyd_Warshall_path(k,j);
    }
}

// 运用Floyd_Warshall算法寻找最短路
void Graph::Floyd_Warshall() {

    // 调用核心算法
    Floyd_Warshall_core();

    // 打印路径
    for (int i = 0; i < V_NUMBER; ++i) {
        for (int j = 0; j < V_NUMBER; ++j) {
            if (i!=j && D[i][j] != inf) {
                std::cout << "The distance " << i << " to " << j << " is: " << D[i][j] << "\t";
                std::cout << "\t" << "The path is:" << i << "\t";
                Floyd_Warshall_path(i, j);
                std::cout << j << std::endl;
            } else if (i!=j && D[i][j] == inf) {
                std::cout << "The distance " << i << " to " << j << " is: not found!" << std::endl;
            }
        }
    }
}

//运用Floyd_Warshall算法计算每个顶点到某个顶点i的最短路径，需要提前调用Floyd_Warshall算法
void Graph::Print_FW_Single(int i) {
    for (int j = 0; j < V_NUMBER; ++j) {
        if (i!=j && D[i][j] != inf) {
            std::cout << "The distance " << i << " to " << j << "\t" << " is: " << D[i][j] << "\t";
            std::cout << "\t" << "The path is:" << i << "\t";
            Floyd_Warshall_path(i, j);
            std::cout << j << std::endl;
        } else if (i!=j && D[i][j] == inf) {
            std::cout << "The distance " << i << " to " << j << " is: not found!" << std::endl;
        }
    }
}

// 运用Floyd_Warshall算法，计算各个顶点‍到达某个点的最短路径
void Graph::find_single(int i) {
    // 调用核心算法
    Floyd_Warshall_core();
    Print_FW_Single(i);
}

// Floyd_Warshall的核心算法
void Graph::Floyd_Warshall_core() {
    // 算法预备工作
    for (int i = 0; i < V_NUMBER; ++i) {
        for (int j = 0; j < V_NUMBER; ++j) {
            P[i][j] = -1;
            if (i!=j) {
                if (edge[i][j]==0){D[i][j] = inf;}
                else {D[i][j] = edge[i][j];}
            } else {
                D[i][j] = 0;
            }
        }
    }

    // 算法实现工作
    for (int k = 0; k < V_NUMBER; ++k) {     // 对每一个节点进行尝试
        for (int i = 0; i < V_NUMBER; ++i) {
            for (int j = 0; j < V_NUMBER; ++j) {
                if (D[i][j] > D[i][k] + D[k][j]) {
                    P[i][j] = k;
                    D[i][j] = D[i][k] + D[k][j];
                }
            }
        }
    }
}

// 运用Floyd_Warshall算法，找到一对顶点之间，相通的两条最短路径
void Graph::find_pair(int i, int j) {
    // 首先调用Floyd_Warshall算法
    Floyd_Warshall_core();
    if (D[i][j]!=inf && D[j][i]!=inf) {

        // 打印i到j的路径
        std::cout << "The distance " << i << " to " << j << "\t" << " is: " << D[i][j] << "\t";
        std::cout << "\t" << "The path is:" << i << "\t";
        Floyd_Warshall_path(i,j);
        std::cout << j << std::endl;

        // 打印j到i的路径
        std::cout << "The distance " << j << " to " << i << "\t" << " is: " << D[j][i] << "\t";
        std::cout << "\t" << "The path is:" << j << "\t";
        Floyd_Warshall_path(j,i);
        std::cout << i << std::endl;
    } else {
        std::cout << "Do not find the path!" << std::endl;
    }
}




