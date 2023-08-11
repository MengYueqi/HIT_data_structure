#include <iostream>
#include "Graph.h"

int main() {
    Graph G = Graph("/Users/mengfanxing/Desktop/DS_lab3/source.txt");
    G.printGraph();
    std::cout << "The algorithm Floyd_Warshall:" << std::endl;
    G.dijkstra(0);
    std::cout << std::endl;
    std::cout << "The algorithm Floyd_Warshall:" << std::endl;
    G.Floyd_Warshall();
    std::cout << std::endl;
    G.find_single(2);
    std::cout << std::endl;
    G.find_pair(2,3);
    return 0;
}
