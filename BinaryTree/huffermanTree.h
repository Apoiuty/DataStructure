//
// Created by Apoiuty on 2019/10/16.
//

#ifndef DATA_STRUCTURE_HUFFERMANTREE_H
#define DATA_STRUCTURE_HUFFERMANTREE_H

struct huffmanNode {
    int weight;
    int tag, left, right;
};

typedef struct huffmanNode HuffermanNode;


/**
 * 霍夫曼树初始化
 * @param h 要初始化的树
 * @param tag 是否有 父节点
 * @param left 左节点
 * @param right 右节点
 */
void Init_HuffmanNode(HuffermanNode *h, int tag, int left, int right);


/**
 * 构造霍夫曼树
 * @param root 根节点
 * @param a
 * @param b
 * @param n
 */
void MakeHuffman(int root, int *a, HuffermanNode *b, int n);

#endif //DATA_STRUCTURE_HUFFERMANTREE_H
