//
// Created by Apoiuty on 2019/8/31.
//

#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

void InitQueue(Queue *Q, int sz) {
    if (sz <= 0)
        printf("Queue size must be positive.\n");
    else {
        Q->front = 0, Q->rear = 0;
        Q->Element = (ElementType *) malloc(sizeof(ElementType) * sz);
        Q->Size = sz;
    }
}

void FreeQueue(Queue *Q, int sz) {
    free(Q->Element);
}

void MakeEmpty(Queue *Q) {
    Q->rear = Q->front = 0;
}

int IsEmpty(Queue *Q) {
    return Q->rear == Q->front;
}

int IsFull(Queue *Q) {
    return Q->front == (Q->rear + 1) % Q->Size;
}

int Length(Queue *Q) {
    return (Q->front - Q->Size + Q->Size) % Q->Size;
}

int EnQueue(Queue *Q, ElementType x) {
    if (!IsFull(Q)) {
        Q->Element[Q->rear] = x;
        Q->rear = (Q->rear + 1) % Q->Size;
        return 1;
    } else
        return 0;
}

ElementType DeQueue(Queue *Q) {
    if (!IsEmpty(Q)) {
        ElementType item = Q->Element[Q->front];
        Q->front = (Q->front + 1) % Q->Size;
        return item;
    } else {
        printf("Queue is empty.\n");
        exit(1);
    }
}

ElementType GetFront(Queue *Q) {
    if (!IsEmpty(Q)) {
        return Q->Element[Q->front];
    } else {
        printf("Queue is empty.\n");
        exit(1);
    }
}

