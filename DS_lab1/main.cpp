#include <iostream>
#include <stack>
#include "Maze.h"


int main() {
    Maze maze;
    maze.printmaze();
    std::cout << "迭代寻找路径的方法：" << std::endl;
    maze.getmaze1();
    std::cout << "递归寻找路径的方法：" << std::endl;
    maze.getmaze2();
    std::cout << "迭代寻找所有路径的方法：" << std::endl;
    maze.getmaze_all();
}
