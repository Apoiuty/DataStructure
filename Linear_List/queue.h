//
// Created by Apoiuty on 2019/8/31.
//

#ifndef DATA_STRUCTURE_QUEUE_H
#define DATA_STRUCTURE_QUEUE_H
#define True 1
#define False 0

typedef int ElementType;
typedef struct queue {
    int rear, front;
    ElementType *Element;
    int Size;
} Queue;

void InitQueue(Queue *Q,int sz);

void FreeQueue(Queue *Q,int sz);

void MakeEmpty(Queue *Q);

int IsEmpty(Queue *Q);

int IsFull(Queue *Q);

int Length(Queue *Q);

int EnQueue(Queue *Q, ElementType x);

ElementType  DeQueue(Queue *Q);

ElementType  GetFront(Queue *Q);


#endif //DATA_STRUCTURE_QUEUE_H
