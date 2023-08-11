//
// Created by 孟繁兴 on 2022/10/18.
//

#include "TranUtil.h"


// 将邻接矩阵表示法的图转化为邻接表表示的
GraphLink TranUtil::TranM_to_L(GraphMatrix GM) {
    GraphLink GL = GraphLink();
    for (int i = 0; i < V_NUMBER; ++i) {
        for (int j = 0; j < V_NUMBER; ++j) {
            if (GM.isEdge(i,j)) {
                GL.add_edge(i,j,GM.getcost(i,j));
            }
        }
    }
    return GL;
}

// 将邻接表表示的图转化为邻接矩阵表示的
GraphMatrix TranUtil::TranL_to_M(GraphLink GL) {
    GraphMatrix GM = GraphMatrix();
    for (int i = 0; i < V_NUMBER; ++i) {
        node *p = GL.getfirstedge(i);
        while (p) {
            GM.add_edge(i,p->vertex,p->cost);
            p = p->next;
        }
    }
    return GM;
}
