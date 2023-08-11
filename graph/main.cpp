#include <iostream>
#include "GraphMatrix.h"
#include "GraphLink.h"
#include "TranUtil.h"

int main() {
    GraphMatrix GL = GraphMatrix();
    GL.DFS1();
    std::cout << std::endl;
    GL.print();
    std::cout << std::endl;
    GL.Prim();
    std::cout << std::endl;
    GL.kruskal();
}
