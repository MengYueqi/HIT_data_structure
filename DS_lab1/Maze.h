//
// Created by 孟繁兴 on 2022/10/2.
//

#ifndef LAB1_MAZE_H
#define LAB1_MAZE_H

#include <iostream>
#include <stack>
#include "stackL.h"

#define LINE_NUMBER 4
#define ROW_NUMBER 5



typedef struct {
    int x;
    int y;
    int v;
} Position;

class Maze{
private:
    // 迷宫数据
    int maze[LINE_NUMBER+2][ROW_NUMBER+2] = {1,1,1,1,1,1,1,
                                             1,0,1,1,0,0,1,
                                             1,1,0,0,1,0,1,
                                             1,0,1,0,0,0,1,
                                             1,0,0,1,1,0,1,
                                            1,1,1,1,1,1,1};
    // 标记数据
    int mark[LINE_NUMBER+2][ROW_NUMBER+2] = {0};
    // 移动方向数据
    int move[8][2] = {0,1,
                      1,1,
                      1,0,
                      1,-1,
                      0,-1,
                      -1,-1,
                      -1,0,
                      -1,1};
    // 是否找到路径的flag
    int flag = 0;
    // 辅助栈
    stackL<Position> s,temp;
    // 辅助结构体p
    Position p1,p2;

public:void disorder_print ();
    void order_print();
    void getmaze1();
    void core_getmaze2(int i=1, int j=1, int v=0);
    void getmaze2();
    bool inStake(Position p);
    void getmaze_all();
    void printmaze() const;

};



#endif //LAB1_MAZE_H
