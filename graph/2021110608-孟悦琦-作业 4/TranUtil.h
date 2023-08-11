//
// Created by 孟繁兴 on 2022/10/18.
//

#ifndef GRAPH_TRANUTIL_H
#define GRAPH_TRANUTIL_H

#include "GraphMatrix.h"
#include "GraphLink.h"


// 转换邻接矩阵和邻接表的转换器类
class TranUtil {
private:

public:
    GraphLink TranM_to_L (GraphMatrix GM);
    GraphMatrix TranL_to_M (GraphLink GL);
};


#endif //GRAPH_TRANUTIL_H
