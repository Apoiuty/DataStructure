//
// Created by Apoiuty on 2019/9/22.
//

#include <stdio.h>
#include "dNode.h"
#include <stdlib.h>

//初始化函数
void InitDNode(DNode *d, int x) {
    d->data = x;
    d->next = d->pre = d;
}

//在当前节点前插入节点
void InsrtDNBefore(DNode *d, DNode *ptr) {
    ptr->next = d;
    ptr->pre = d->pre;
    d->pre->next = ptr;
    d->pre = ptr;
}

//在当前节点后插入节点
void InsrtDNAfter(DNode *d, DNode *ptr) {
    ptr->next = d->next;
    ptr->pre = d;
    d->next->pre = ptr;
    d->next = ptr;
}

//删除节点
DNode *DeleteDNAT(DNode *d) {
    if (d->next == d)
        return NULL;
    else{
        d->pre->next=d->next;
        d->next->pre=d->pre;
        return d->next;
//        返回指向当前节点的指针
    }
}

//申请双链表节点
DNode *NewDNode(int x) {
    DNode *newNode = (DNode *) malloc(sizeof(DNode));
    newNode->next = newNode->pre = NULL;
    newNode->data = x;
    return newNode;
}