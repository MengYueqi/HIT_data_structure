//
// Created by Meng on 2022/10/17.
//

#include "GraphMatrix.h"

// 向图中增加一个边
void GraphMatrix::add_edge(int i, int j, int cost) {
    edge[i][j] = cost;
}

// 用邻接矩阵表示图的构造函数
GraphMatrix::GraphMatrix() {
    int i,j,cost;
    std::cin >> i >> j >> cost;

    // 当输入任意负值时，结束输入
    while (i>=0 && j>=0){
        add_edge(i,j,cost);
        add_edge(j,i,cost);
        std::cin >> i >> j >> cost;
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
            std::cout << i << "\t";
            BFS2_core(i);
            std::cout << std::endl;
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

// 打印遍历序列
void GraphMatrix::sequence() {
    for (int i = 0; i < V_NUMBER; ++i) {
        for (int j = 0; j < V_NUMBER; ++j) {
            if (number[j] == i+1) {
                std::cout << j << "\t";
            }
        }
    }
    std::cout << std::endl;
}

// dijkstra算法，找到目前距离最短的节点
int GraphMatrix::dijkstra_chooseMin(int i) {
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
void GraphMatrix::dijkstra_print_path(int i, int j) {
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
void GraphMatrix::dijkstra(int i) {
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
void GraphMatrix::Floyd_Warshall_path(int i, int j) {
    int k = P[i][j];
    if (k!=-1) {
        Floyd_Warshall_path(i,k);
        std::cout << k << "\t";
        Floyd_Warshall_path(k,j);
    }
}

// 运用Floyd_Warshall算法寻找最短路
void GraphMatrix::Floyd_Warshall() {

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

// Floyd_Warshall的核心算法
void GraphMatrix::Floyd_Warshall_core() {
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

// Prim算法计算图的最小生成树
void GraphMatrix::Prim(){
    int lowcost[V_NUMBER]; // 算法辅助数组，加入生成树所需要的最短距离花费
    int closest[V_NUMBER]; // 加入时依附的边
    int min,j,k;

    // 算法初始化
    for (int i = 1; i < V_NUMBER; i++){
        lowcost[i] = edge[0][i];
        closest[i] = 0;
    }
    
    // 算法核心步骤
    for (int i = 1; i < V_NUMBER; i++){
        min = lowcost[i];
        k = i;
        for (int j = 1; j < V_NUMBER; j++){
            // 距离为0说明并不存在相关联的边
            if (min==0 && lowcost[j]!=0 && lowcost[j]!=inf) {
                min = lowcost[j];
                k = j;
            } else if (lowcost[j] < min && lowcost[j]!=0){ // 禁止对min进行赋0操作
                min = lowcost[j];
                k = j;
            }
        }
        
        // 输出最小生成树中的边
        std::cout << "(" << k << "," << closest[k] << ")" << "\t" << "cost:" << lowcost[k] << std::endl;
        lowcost[k] = inf;
        for (int i = 1; i < V_NUMBER; i++){
            if (lowcost[i]==0 && edge[i][k]!=0){
                lowcost[i] = edge[i][k];
                closest[i] = k;
            } else if (lowcost[i]!=inf && edge[i][k]<lowcost[i] && edge[i][k]!=0) {
                lowcost[i] = edge[i][k];
                closest[i] = k;
            }
        }
    }
}

// 对图中的边，运用快排算法进行排序
void GraphMatrix::Sort(Edge* edges,int lo,int hi){
    if (lo >= hi){return;}
    int i = lo+1;
    int j = hi;
    while (true){
        while (edges[i].len <= edges[lo].len){ 
            i++;
            if(i == hi){break;}
        }
        while (edges[j].len >= edges[lo].len){ 
            j--;
            if(j == lo){break;}
        }
        if (i >= j){break;}
        swapEdge(edges,i,j);
    }
    swapEdge(edges,lo,j);
    Sort(edges,lo,j-1);
    Sort(edges,j+1,hi);
}

// 辅助函数，交换边
void GraphMatrix::swapEdge(Edge* edges,int i,int j){
    Edge temp;
    temp = edges[i];
    edges[i] = edges[j];
    edges[j] = temp;
}

// 并查集函数，找到一个元素所在的根集合
int GraphMatrix::Find(int *father,int i){
    int ret = 0;
    while (i > 0){
        ret = i;
        i = father[i];
    }
    return ret;
}

// 运用kruskal算法计算最小生成树
void GraphMatrix::kruskal(){
    // 创建不少于最大边数的数组
    Edge edges[(V_NUMBER*(V_NUMBER-1))/2];
    // 将边的信息录入数组，并统计边数
    int eNum = 0;
    for (int i = 0; i < V_NUMBER; i++){
        for (int j = i+1; j < V_NUMBER; j++){
            if (edge[i][j] != 0){
                edges[eNum].begin = i;
                edges[eNum].end = j;
                edges[eNum].len = edge[i][j];
                eNum++;
            }
        }
    }
    Sort(edges,0,eNum-1);

    // 创建并查集数组
    int father[V_NUMBER];
    for (int i = 0; i < V_NUMBER; i++){
        father[i] = -1;
    }

    // kruskal算法核心步骤
    int eBegin,eEnd;
    for (int i = 0; i < eNum; i++){
        // 分别计算边的两个顶点所在的集合
        eBegin = Find(father,edges[i].begin);
        eEnd = Find(father,edges[i].end);
        if (eBegin != eEnd) {
            father[eBegin] = eEnd; // 合并两集合
            std::cout << "(" << edges[i].begin << "," << edges[i].end << ")" << "\t" << "cost:" << edges[i].len << std::endl;
        }
    }
}