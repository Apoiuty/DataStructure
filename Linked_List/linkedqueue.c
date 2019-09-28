//
// Created by Apoiuty on 2019/9/22.
//

#include "linkedqueue.h"

//初始化链队列
void InitLinkedQueue(LinkedQueue *Q) {
    Q->queue = (LinkedList *) malloc(sizeof(LinkedList));
    InitLinkedList(Q->queue);
}

//队列中插入一个新元素
void In(LinkedQueue *Q, int x) {
    SetPos(Q->queue, (Q->queue)->size - 1);
//    设置队尾为当前节点
    InsertLAfter(Q->queue, x);
}

//在队列中删除一个元素
int Out(LinkedQueue *Q) {
    if (Q->queue->size == 0) {
        printf("Empty queue.\n");
        exit(1);
    } else {
        SetPos(Q->queue, 0);
        int tem = GetData(Q->queue);
        DeleteAT(Q->queue);
        return tem;
    }
}

//取队列头部元素
int Front(LinkedQueue *q) {
    if (q->queue->size == 0) {
        printf("Empty queue.\n");
        exit(1);
    } else {
        SetPos(q->queue, 0);
        int tem = GetData(q->queue);
        return tem;
    }
}

//清除队列中数据元素
void ClearLQ(LinkedQueue *q) {
    Node *next, *cur;
    cur = q->queue->front;
    while (cur) {
        next = cur->next;
        free(cur);
        cur = next;
    }
    InitLinkedList(q->queue);
}

//判断队列是否为空
int isEmptyLQ(LinkedQueue *Q) {
    return Q->queue->size == 0;
}
