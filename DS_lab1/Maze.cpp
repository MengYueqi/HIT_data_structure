//
// Created by 孟繁兴 on 2022/10/2.
//

#include "Maze.h"

// 顺序打印栈的算法
void Maze::order_print() {
    while (!s.empty()) {
        std::cout << "(" << s.top().x << "," << s.top().y << ")" << "  ";
        s.pop();
    }
    if (flag == 1) {std::cout << std::endl;}
}

// 倒序打印栈的算法
void Maze::disorder_print () {
    while (!s.empty()) {
        temp.push(s.top());
        s.pop();
    }

    s.push(temp.top());
    temp.pop();

    while (!temp.empty()) {
        std::cout << "(" << temp.top().x << "," << temp.top().y << ")" << "  ";
        s.push(temp.top());
        temp.pop();
    }
    std::cout << std::endl;
};

// 迭代实现迷宫寻路
void Maze::getmaze1(){
    int i = 1;
    int j = 1;
    int v = 0;
    int g,h;
    p1.x = 1; p1.y = 1; p1.v = 0;
    s.push(p1);
    do {
        g = i+move[v][0];
        h = j+move[v][1];
        if (i==LINE_NUMBER && j==ROW_NUMBER){
            disorder_print();
            for (int k = 0; k < LINE_NUMBER+2; ++k) {
                for (int l = 0; l < ROW_NUMBER+2; ++l) {
                    mark[k][l] = 0;
                }
            }
            s.makeNull();
            temp.makeNull();
            return;
        }
        if (maze[g][h] == 0 && mark[g][h] == 0){
            p1.x = i; p1.y = j; p1.v = v;
            s.push(p1);
            i = g; j = h; v = 0;
            mark[i][j] = 1;
        } else if (v<7) { v+=1; }
        else {
            do  {
                s.pop();
                if (!s.empty()) {
                    i = s.top().x;
                    j = s.top().y;
                    v = s.top().v + 1;
                }
            } while (v == 8 && !s.empty());
        }
    } while (!s.empty() && v!=8);
    std::cout << "未找到路径！" << std::endl;
}

// 递归实现迷宫寻路的核心算法
void Maze::core_getmaze2(int i, int j, int v) {
    if (mark[i][j] == 1 || maze[i][j] == 1) {
        mark[i][j] = 1;
        return;
    }
    if (i==LINE_NUMBER && j==ROW_NUMBER) {
        flag = 1;
        p1.x = i; p1.y = j; p1.v = v;
        s.push(p1);
        return;
    }
    while (v <= 7) {
        if (!flag) {
            core_getmaze2(i + move[v][0], j + move[v][1], 0);
            v++;
        } else {
            p1.x = i; p1.y = j; p1.v = v;
            s.push(p1);
            return;
        }
    }
}

// 递归实现迷宫寻路
void Maze::getmaze2() {
    core_getmaze2(); // 调用迷宫寻路的核心算法，并把结果压到类栈里
    order_print(); // 顺序打印栈
    if (flag == 0) {
        std::cout << "未找到路径！" << std::endl;
    }
    s.makeNull();
    temp.makeNull();
    flag = 0;
}

// 查找某元素是否在栈中
bool Maze::inStake(Position p) {
    Position mid;
    bool ret = false;
    while (!s.empty()) {
        if ((p.x == s.top().x) && (p.y == s.top().y)){ret = true;}
        mid = s.top();
        s.pop();
        temp.push(mid);
    }
    while (!temp.empty()){
        mid = temp.top();
        s.push(mid);
        temp.pop();
    }
    return ret;
}

// 查找所有路径的办法
void Maze::getmaze_all(){
    int i = 1;
    int j = 1;
    int v = 0;
    int g,h;
    p1.x = 1; p1.y = 1; p1.v = 0;
    s.push(p1);
    do {
        g = i+move[v][0];
        h = j+move[v][1];
        p2.x = g;
        p2.y = h;
        if (i==LINE_NUMBER && j==ROW_NUMBER){
            flag = 1;
            p1.x = i; p1.y = j; p1.v = v;
            s.push(p1);
            disorder_print();
            s.pop();
            i = s.top().x;
            j = s.top().y;
            v = s.top().v+1;
            g = i+move[v][0];
            h = j+move[v][1];
            p2.x = g;
            p2.y = h;
            s.pop();
        }
        if (maze[g][h] == 0 && !inStake(p2)){
            p1.x = i; p1.y = j; p1.v = v;
            s.push(p1);
            i = g; j = h; v = 0;
        } else if (v<7) { v+=1; }
        else {
            do {
                i = s.top().x;
                j = s.top().y;
                v = s.top().v+1;
                s.pop();
            } while (v == 8 && !s.empty());
        }
    } while (!s.empty() && v!=8);
    if (flag == 0) {
        std::cout << "未找到路径！" << std::endl;
    }
}

void Maze::printmaze() const {
    std::cout << "迷宫如下" << std::endl;
    for (int i = 1; i <= LINE_NUMBER; ++i) {
        for (int j = 1; j <= ROW_NUMBER; ++j) {
            std::cout << maze[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}