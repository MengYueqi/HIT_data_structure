//
// Created by 孟繁兴 on 2022/10/10.
//

#include "HuffmanTree.h"

// 读取文章的算法
void HuffmanTree::read_text() {
    char ch1;
    while (ch1 != '\0') {

    }
}

// 选择哈夫曼树的最小权两节点。
void HuffmanTree::select_min(int len) {
    int i, temp;
    node1 = node2 = -1;
    for (int i = 0; i < len; ++i) {
        if (HuffmanTree[i].parent == -1) {
            // 如果node1,node2还未被标记，那么标记他
            if (node1 == -1) {
                node1 = i;
                continue;
            }
            if (node2 == -1) {
                node2 = i;
                continue;
            }

            // 保持node1中存储的元素最小
            if (HuffmanTree[node1].weight > HuffmanTree[node2].weight) {
                temp = node1;
                node1 = node2;
                node2 = temp;
            }
            if (HuffmanTree[node2].weight > HuffmanTree[i].weight) {
                node2 = i;
                continue;
            }
        }
    }
}

// 通过读取的频数表，生成哈夫曼树的算法
void HuffmanTree::creat_HFTree(CountTable CT) {
    HuffmanTree = new HTNODE[2*CT.getlen()-1];
    count = 2*CT.getlen()-1;
    for (int i = 0; i < count; ++i) {
        // 初始化树
        HuffmanTree[i].parent = -1;
        HuffmanTree[i].lchild = -1;
        HuffmanTree[i].rchild = -1;
        if (i < CT.getlen()) {
            HuffmanTree[i].weight = CT.getcnt(i);
        }
    }

    // 生成哈夫曼树
    for (int j = CT.getlen(); j < count; ++j) {
        select_min(j);
        HuffmanTree[j].weight = HuffmanTree[node1].weight + HuffmanTree[node2].weight;
        HuffmanTree[node1].parent = HuffmanTree[node2].parent = j;
        HuffmanTree[j].lchild = node1;
        HuffmanTree[j].rchild = node2;
    }

}

void HuffmanTree::print_Tree() {
    for (int i = 0; i < count; ++i) {
        std::cout << HuffmanTree[i].weight << "\t" << HuffmanTree[i].parent << "\t"
        << HuffmanTree[i].rchild << "\t" << HuffmanTree[i].lchild << std::endl;
    }
}

// 调用第i个位置parent值的算法
int HuffmanTree::getparent(int i) const {
    return HuffmanTree[i].parent;
}

// 调用第i个位置lchild值的算法
int HuffmanTree::getlchild(int i) const {
    return HuffmanTree[i].lchild;
}

// 调用第i个位置rchild值的算法
int HuffmanTree::getrchild(int i) const {
    return HuffmanTree[i].rchild;
}
