#include <iostream>
#include "HuffmanTree.h"
#include "CountTable.h"
#include "HuffmanTable.h"
#include "FILEUtil.h"

int main() {
    HuffmanTree h;
    CountTable CT;
    CT.readtext("/Users/mengfanxing/Desktop/DS_lab2/source.txt");
    std::cout << "The countTabel is :" << std::endl;
    CT.printTable();
    h.creat_HFTree(CT);
    HuffmanTable HT;
    HT.update_HFTable(h);
    std::cout << "The HuffmanTable is:" << std::endl;
    HT.printTable();
    std::cout << "The code after encode is:" << std::endl;
    std::cout << HT.encode("/Users/mengfanxing/Desktop/DS_lab2/source.txt") << std::endl;
    std::ofstream ofs;
    ofs.open("/Users/mengfanxing/Desktop/DS_lab2/16bite.txt",std::ios::out);
    ofs << HT.encode("/Users/mengfanxing/Desktop/DS_lab2/source.txt");
    std::cout << "The code after decode is:" << std::endl;
    std::cout << HT.decode("/Users/mengfanxing/Desktop/DS_lab2/code.dat") << std::endl;
    FILEUtil fl;
    float cr = fl.size("/Users/mengfanxing/Desktop/DS_lab2/code.dat")/fl.size("/Users/mengfanxing/Desktop/DS_lab2/source.txt");
    std::cout << "The compression ratio is " << cr << std::endl;
}
