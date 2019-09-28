//
// Created by Apoiuty on 2019/9/22.
//

#include "cnode.h"
#include <stdlib.h>
#include <stdio.h>

//初始化函数
void InitCNode(CNode *c, int x) {
    c->next = c;
    c->data = x;
}

//插入和删除节点, --c--ptr--
void InsertCNAfter(CNode *c, CNode *ptr) {
    ptr->next = c->next;
    c->next = ptr;
}

//循环链表删除本节点后继的函数
CNode *DeleteCNAfter(CNode *c) {
    if (c->next == c) {
        return NULL;
    } else {
        CNode *temp = c->next;
        c->next = c->next->next;
        return temp;
    }
}

//申请循环链表节点空间的函数
CNode *NewCNode(int x) {
    CNode *newNode = (CNode *) malloc(sizeof(CNode));
    if (newNode) {
        newNode->data = x;
        newNode->next = NULL;
        return newNode;
    } else {
        printf("Allocation failure.\n");
        exit(1);
    }
}