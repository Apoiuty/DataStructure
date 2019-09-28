//
// Created by Apoiuty on 2019/9/2.
//

#ifndef DATA_STRUCTURE_LINKEDLIST_H
#define DATA_STRUCTURE_LINKEDLIST_H

#include "node.h"

struct linkedList {
    Node *front, *rear;
    Node *pre, *cur;
    int size;
    int pos;
};
//链表数据结构

typedef struct linkedList LinkedList;

//初始化链表, L为要初始化的链表
void InitLinkedList(LinkedList *L);

int IsEmptyList(LinkedList *L);
//判断链表是否为空

int NextNode(LinkedList *L);
//将后置节点置为当前的函数

int SetPos(LinkedList *L, int pos);
//重置链表节点位置

void InsertAt(LinkedList *L, int x);
//链表中当前位置插入新节点的函数

void InsertLAfter(LinkedList *L, int x);
//在当前节点后插入

void DeleteAT(LinkedList *L);
//删除当前节点

void DelteLAfter(LinkedList *L);
//删除后一个节点

int GetData(LinkedList *L);
//获取当前节点处的值

void SetData(LinkedList *L, int x);
//链表中修改当前节点中的数据

void ClearLinkedList(LinkedList *L);
//清空链表

//打印链表
void PrintOutL(Node *head);

//创建长度为N的链表
Node *CreatL(int n);

#endif //DATA_STRUCTURE_LINKEDLIST_H


