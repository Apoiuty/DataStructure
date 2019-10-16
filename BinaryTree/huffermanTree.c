//
// Created by Apoiuty on 2019/10/16.
//

#include <limits.h>
#include "huffermanTree.h"


/**
 * 构造霍夫曼树
 * @param root 根节点
 * @param a 权重
 * @param b
 * @param n
 */
void MakeHuffman(int root, int *a, HuffermanNode *b, int n) {
//    分配权重
    for (int i = 0; i < n; ++i) {
        b[i].weight = a[i];
    }

    int i, j, m1, m2, i1, i2;
    for (i = 1; i <= n - 1; i++) {
        m2 = m1 = INT_MAX;
        i1 = i2 = -1;
//        找到两个最小权重
        for (j = 0; j <= n + i - 1; j++) {
            if (b[j].weight < m1 && b[j].tag == 0) {
                m2 = m1;
                i2 = i1;
                m1 = b[j].weight;
                i1 = j;
            } else if (b[j].weight < m2 && b[j].tag == 0) {
                m2 = b[j].weight;
                i2 = j;
            }
        }

        b[i1].tag = b[i2].tag = 1;

//        构造子树
        b[n - 1 + i].weight = m1 + m2;
        b[n - 1 + i].tag = 1;
        b[n - 1 + i].left = m1;
        b[n - 1 + i].right = m2;
    }

    root = 2 * n - 2;
}
