//
// Created by 孟繁兴 on 2022/10/19.
//

#include <cstdio>
#include "FILEUtil.h"

float FILEUtil::size(char *name) {
    FILE *fp = fopen(name, "r");
    fseek(fp, 0, SEEK_END);
    return ftell(fp);
}
