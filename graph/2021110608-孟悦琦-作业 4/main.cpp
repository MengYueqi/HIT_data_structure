#include <iostream>
#include "GraphMatrix.h"
#include "GraphLink.h"
#include "TranUtil.h"

int main() {
    GraphMatrix GM = GraphMatrix("/Users/mengfanxing/Desktop/graph/GM.txt");
    GM.BFS2();
    for (int i = 0; i < V_NUMBER; ++i) {
        std::cout << i << "  " << GM.getnumber(i) << "\n";
    }
    return 0;
}
