//
// Created by Apoiuty on 2019/9/1.
//

#ifndef DATA_STRUCTURE_NODE_H
#define DATA_STRUCTURE_NODE_H

#include <stdio.h>
#include <stdlib.h>
//Node结构
struct node {
    int data;
    struct node *next;
};
typedef struct node Node;

//初始化节点
void InitNode(Node *N, int item, Node *ptr);

//N节点后插入p节点
void InsertAfter(Node *N, Node *p);

//删除N节点后的节点
Node *DeleteAfter(Node *N);

//以N为后继节点创建节点
Node *Get_Node(Node *Next, int x);

//释放节点
void FreeNode(Node *);

#endif //DATA_STRUCTURE_NODE_H
