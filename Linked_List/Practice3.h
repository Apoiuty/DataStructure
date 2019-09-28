//
// Created by Apoiuty on 2019/9/22.
//

#ifndef DATA_STRUCTURE_PRACTICE3_H
#define DATA_STRUCTURE_PRACTICE3_H

#include "node.h"
#include "linkedlist.h"
#include "dNode.h"

struct Term {
    double coeff;
    int power;
    struct Term *pre, *next;
};

typedef struct Term term;

//将节点p开始的链表复制到链表list的尾部
void Append(Node *p, Node *list);

//Josephus问题用循环链表解决, n个人从s开始报数, 报到m个人
void Josephus2(int n, int s, int m);

//单链表翻转
void InverseLinkedList(LinkedList *L);

//删除大于m小于M的元素
void Delete_n2M(LinkedList *L, int m, int M);

void Polynomial(void);

//将单链表中的元素按正负分类
DNode *Sort(LinkedList *L);


#endif //DATA_STRUCTURE_PRACTICE3_H
