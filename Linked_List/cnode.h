//
// Created by Apoiuty on 2019/9/22.
//

#ifndef DATA_STRUCTURE_CNODE_H
#define DATA_STRUCTURE_CNODE_H

struct cNode {
    int data;
    struct cNode *next;
};

typedef struct cNode CNode;

//初始化函数
void InitCNode(CNode *c, int x);

//插入和删除节点,--c--ptr--
void InsertCNAfter(CNode *c, CNode *ptr);

//循环链表删除本节点后继的函数
CNode *DeleteCNAfter(CNode *c);

//申请循环链表节点空间的函数
CNode *NewCNode(int x);

#endif //DATA_STRUCTURE_CNODE_H
