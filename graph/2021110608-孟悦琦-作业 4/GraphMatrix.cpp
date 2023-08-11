//
// Created by 孟繁兴 on 2022/10/17.
//

#include "GraphMatrix.h"

// 向图中增加一个边
void GraphMatrix::add_edge(int i, int j, int cost) {
    edge[i][j] = cost;
}

// 用邻接矩阵表示图的构造函数
GraphMatrix::GraphMatrix(const char *name) {
    int i,j;

    // 如果有初始化文件，那么进行初始化
    if (name) {
        // 创建读取文件流
        std::ifstream ifs;
        ifs.open(name, std::ios::in);

        // 通过文件设置边
        if (ifs.is_open()) {
            // 读取文件中的边
            while (!ifs.eof()) {
                ifs >> i >> j;
                add_edge(i,j);
                add_edge(j,i);
            }
            ifs.close();
        } else {
            std::cerr << "Unable to open file" << std::endl;
        }
    }
}

// 打印邻接矩阵的算法
void GraphMatrix::print() {
    int i,j;
    for (i = 0; i < V_NUMBER; ++i) {
        for (j = 0; j < V_NUMBER; ++j) {
            std::cout << edge[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

/// 虽然两个函数是一样的，但我还是认为写两个更合适一点

// 判断i，j之间是否有边
bool GraphMatrix::isEdge(int i, int j) {
    return edge[i][j];
}

// 获取以i，j为顶点的边的权值
int GraphMatrix::getcost(int i, int j) {
    return edge[i][j];
}

// 从某个节点开始,深度优先搜索的递归核心算法
void GraphMatrix::DFS1_core(const int i)  {
    std::cout << i << "\t";
    // 对遍历进行编号
    n++;
    number[i] = n;
    visit[i] = 1;
    for (int j = 0; j < V_NUMBER; ++j) {
        // 如果两个顶点之间有边，另一个顶点没被访问过，则递归访问
        if (edge[i][j] && visit[j] == 0) {
            DFS1_core(j);
        }
    }
}

// 深度优先搜索的递归算法
void GraphMatrix::DFS1() {
    for (int i = 0; i < V_NUMBER; ++i) {
        if (visit[i] == 0) {
            DFS1_core(i);
            std::cout << std::endl;
        }
    }
    reset();
}

// 深度优先搜索的迭代形式
void GraphMatrix::DFS2() {
    std::stack<int> s;
    for (int k = 0; k < V_NUMBER; ++k) {
        if (visit[k] == 0) {
            if (k!=0) {std::cout << std::endl;} // 不为0说明不是第一次，再打印endl
            s.push(k);
            // 对遍历进行编号
            n++;
            number[k] = n;
            visit[k] = 1;
            std::cout << k << "\t";
        }
        while (!s.empty()) {
            int i = s.top();
            int j;
            for (j = 0; j < V_NUMBER; ++j) {
                if (edge[i][j] && visit[j] == 0) {
                    // 对遍历进行编号
                    n++;
                    number[j] = n;

                    visit[j] = 1;
                    s.push(j);
                    std::cout << j << "\t";
                    break;
                }
            }
            // 与顶点数相等，说明一个新顶点都没找到，这样把它弹出栈
            if (j == V_NUMBER) {
                s.pop();
            }
        }
    }
    // 换行符补充调整
    std::cout << std::endl;
    reset();
}

// 广度优先算法的迭代形式
void GraphMatrix::BFS1() {
    std::queue<int> q;
    for (int i = 0; i < V_NUMBER; ++i) {
        if (visit[i] == 0) {
            if (i!=0) {std::cout << std::endl;} // 不为0说明不是第一次，再打印endl
            q.push(i);
            // 对遍历进行编号
            n++;
            number[i] = n;
            visit[i] = 1;
        }
        while (!q.empty()) {
            int k = q.front();
            for (int j = 0; j < V_NUMBER; ++j) {
                if (edge[k][j] && visit[j] == 0) {
                    q.push(j);
                    // 对遍历进行编号
                    n++;
                    number[j] = n;
                    visit[j] = 1;
                }
            }
            q.pop();
            std::cout << k << "\t";
        }
    }
    // 换行符补充调整
    std::cout << std::endl;
    reset();
}

// 广度优先算法的递归形式核心算法
void GraphMatrix::BFS2_core(int i) {
    std::vector<int> v = std::vector<int>(); // 记录访问了哪些节点
    for (int j = 0; j < V_NUMBER; ++j) {
        if (edge[i][j] && visit[j] == 0) {
            // 对遍历进行编号
            n++;
            number[j] = n;
            visit[j] = 1;
            std::cout << j << "\t";
            v.push_back(j);
        }
    }
    for (int j = 0; j < v.size(); ++j) {
        BFS2_core(v[j]);
    }
}

// 广度优先算法的递归形式
void GraphMatrix::BFS2() {
    for (int i = 0; i < V_NUMBER; ++i) {
        if (visit[i] == 0) {
            // 对遍历进行编号
            n++;
            number[i] = n;
            visit[i] = 1;
            BFS2_core(i);
            std::cout << i << std::endl;
        }
    }
    reset();
}

// 重置函数,在做完遍历等操作后重置辅助单元
void GraphMatrix::reset() {
    for (int i = 0; i < V_NUMBER; ++i) {
        visit[i] = 0;
    }
    n = 0;
}

// 判断某个顶点的度
int GraphMatrix::degree(int i) {
    int cnt = 0;
    for (int j = 0; j < V_NUMBER; ++j) {
        if (edge[i][j]) {
            cnt++;
        }
    }
    return cnt;
}

// 获取某个节点的遍历编码
int GraphMatrix::getnumber(int i) {
    return number[i];
}





