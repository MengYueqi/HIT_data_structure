//
// Created by Meng on 2022/10/17.
//

#include "GraphLink.h"

// 向图中添加一条边，连接i，j，权为cost（默认为1）
void GraphLink::add_edge(int i, int j, int cost) {
    // 添加以i为起点的
    EdgeNode *node1 = new EdgeNode;
    node1->vertex = j;
    node1->cost = cost;
    node1->next = vertex_list[i].firstedge;
    vertex_list[i].firstedge = node1;
}

// 初始化一个用邻接表表示的图
GraphLink::GraphLink() {
    // 首先将所有节点连接的边置空
    for (int i = 0; i < V_NUMBER; ++i) {
        vertex_list[i].firstedge = nullptr;
    }
    
    // 创建输入临时变量
    int i,j;
    std::cin >> i >> j;

    // 当输入任意负值时，结束输入
    while (i>=0 && j>=0){
        add_edge(i,j);
        add_edge(j,i);
        std::cin >> i >> j;
    }
    

}

// 打印邻接表的算法
void GraphLink::print() {
    for (int i = 0; i < V_NUMBER ; ++i) {
        EdgeNode *node = vertex_list[i].firstedge;
        std::cout << i << "\t";
        while (node) {
            std::cout << node->vertex << "\t";
            node = node->next;
        }
        std::cout << std::endl;
    }
}

// 返回邻接表头节点所指的边节点
node *GraphLink::getfirstedge(int i) {
    return vertex_list [i].firstedge;
}

// 从某个节点开始,深度优先搜索的递归核心算法
void GraphLink::DFS1_core(const int i) {
    node *p;
    std::cout << i << "\t";
    // 对遍历进行编号
    n++;
    vertex_list[i].identifier = n;
    visit[i] = 1;
    p = vertex_list[i].firstedge;
    while (p) {
        // 如果两个顶点之间有边，另一个顶点没被访问过，则递归访问
        if (visit[p->vertex] == 0) {
            DFS1_core(p->vertex);
        }
        p = p->next;
    }
}

// 深度优先搜索的递归算法
void GraphLink::DFS1() {
    for (int i = 0; i < V_NUMBER; ++i) {
        if (visit[i] == 0) {
            DFS1_core(i);
            std::cout << std::endl;
        }
    }
    reset();
}

// 广度优先算法的迭代形式
void GraphLink::BFS1() {
    std::queue<VertexNode> q;
    for (int i = 0; i < V_NUMBER; ++i) {
        if (visit[i] == 0) {
            if (i!=0) {std::cout << std::endl;} // 不为0说明不是第一次，再打印endl
            q.push(vertex_list[i]);
            // 对遍历进行编号
            n++;
            vertex_list[i].identifier = n;
            visit[i] = 1;
            std::cout << i << "\t";
        }
        while (!q.empty()) {
            node* p = q.front().firstedge;
            while (p) {
                if (visit[p->vertex] == 0) {
                    q.push(vertex_list[p->vertex]);
                    visit[p->vertex] = 1;
                    // 对遍历进行编号
                    n++;
                    vertex_list[p->vertex].identifier = n;
                    std::cout << p->vertex << "\t";
                }
                p = p->next;
            }
            q.pop();
        }
    }
    reset();
}

// 深度优先搜索的迭代算法
void GraphLink::DFS2() {
    std::stack<node *> s;
    for (int k = 0; k < V_NUMBER; ++k) {
        if (visit[k] == 0) {
            if (k!=0) {std::cout << std::endl;} // 不为0说明不是第一次，再打印endl
            s.push(vertex_list[k].firstedge);

            // 对遍历进行编号
            n++;
            vertex_list[k].identifier = n;

            visit[k] = 1;
            std::cout << k << "\t";
        }
        while (!s.empty()) {
            node *p = s.top();
            while (p) {
                if (visit[p->vertex] == 0) {
                    visit[p->vertex] = 1;

                    // 对遍历进行编号
                    n++;
                    vertex_list[p->vertex].identifier = n;

                    s.push(vertex_list[p->vertex].firstedge);
                    std::cout << p->vertex << "\t";
                    break;
                }
                p = p->next;
            }
            // 与顶点数相等，说明一个新顶点都没找到，这样把它弹出栈
            if (p == nullptr) {
                s.pop();
            }
        }
    }
    std::cout << std::endl;
    reset();
}

// 广度优先算法的递归形式核心算法
void GraphLink::BFS2_core(int i) {
    std::vector<int> v = std::vector<int>(); // 记录访问了哪些节点
    node *p = vertex_list[i].firstedge;
    while (p) {
        if (visit[p->vertex] == 0) {

            // 对遍历进行编号
            n++;
            vertex_list[p->vertex].identifier = n;

            visit[p->vertex] = 1;
            std::cout << p->vertex << "\t";
            v.push_back(p->vertex);
        }
        p = p->next;
    }
    for (int j = 0; j < v.size(); ++j) {
        BFS2_core(v[j]);
    }
}

// 广度优先算法的递归形式
void GraphLink::BFS2() {
    for (int i = 0; i < V_NUMBER; ++i) {
        if (visit[i] == 0) {
            // 对遍历进行编号
            n++;
            vertex_list[i].identifier = n;
            visit[i] = 1;
            std::cout << i << "\t";
            BFS2_core(i);
            std::cout << std::endl;
        }
    }
    reset();
}

// 重置函数,在做完遍历等操作后重置辅助单元
void GraphLink::reset() {
    for (int i = 0; i < V_NUMBER; ++i) {
        visit[i] = 0;
    }
    n = 0;
}

// 判断某个顶点的度
int GraphLink::degree(int i) {
    node *p = vertex_list[i].firstedge;
    int cnt = 0;
    while (p) {
        p = p->next;
        cnt ++;
    }
    return cnt;
}

// 获取一个点的标号
int GraphLink::getIdentifer(int i) {
    return vertex_list[i].identifier;
}

// 输出遍历序列
void GraphLink::sequence() {
    for (int i = 0; i < V_NUMBER; ++i) {
        for (int j = 0; j < V_NUMBER; ++j) {
            if (vertex_list[j].identifier == i+1) {
                std::cout << j << "\t";
            }
        }
    }
    std::cout << std::endl;
}

