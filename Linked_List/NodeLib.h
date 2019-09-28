//
// Created by Apoiuty on 2019/9/2.
//

#include "node.h"

#ifndef DATA_STRUCTURE_NODELIB_H
#define DATA_STRUCTURE_NODELIB_H
enum appendnewline {
    noNewLine, newLine
};

typedef enum appendnewline AppendNewLine;

void PrintList(Node *head, AppendNewLine addnl);

int FindNode(Node *head, int x);

void InsertFront(Node **head, int x);

void DeleteAt(Node **head);

void Delte(Node **head, int x);
//删除单链表中值为x的节点

void InsertOrder(Node **head, int x);
//在有序链表中插入新节点

static void ClearList(Node **head);
//清空链表
#endif //DATA_STRUCTURE_NODELIB_H
