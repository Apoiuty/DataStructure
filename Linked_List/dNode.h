//
// Created by Apoiuty on 2019/9/22.
//

#ifndef DATA_STRUCTURE_DNODE_H
#define DATA_STRUCTURE_DNODE_H
struct dNode {
    struct dNode *pre, *next;
    int data;
};

typedef struct dNode DNode;

//初始化函数
void InitDNode(DNode *d, int x);

//在当前节点前插入节点
void InsrtDNBefore(DNode *d, DNode *pre);

//在当前节点后插入节点
void InsrtDNAfter(DNode *d, DNode *next);

//删除节点
DNode *DeleteDNAT(DNode *d);

//申请双链表节点
DNode *NewDNode(int x);

#endif //DATA_STRUCTURE_DNODE_H
