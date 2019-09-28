//
// Created by Apoiuty on 2019/9/22.
//

#ifndef DATA_STRUCTURE_LINKEDQUEUE_H
#define DATA_STRUCTURE_LINKEDQUEUE_H

#include "linkedlist.h"
//队列数据结构
struct linkedqueue{
    LinkedList *queue;
};

typedef struct linkedqueue LinkedQueue;

//初始化链队列
void InitLinkedQueue(LinkedQueue *Q);

//队列中插入一个新元素
void In(LinkedQueue *Q,int x);

//在队列中删除一个元素
int Out(LinkedQueue *Q);

//取队列头部元素
int Front(LinkedQueue *q);

//清除队列中数据元素
void ClearLQ(LinkedQueue *q);

//判断队列是否为空
int isEmptyLQ(LinkedQueue *Q);


#endif //DATA_STRUCTURE_LINKEDQUEUE_H
