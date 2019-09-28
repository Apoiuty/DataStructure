//
// Created by Apoiuty on 2019/9/22.
//

#ifndef DATA_STRUCTURE_CLNKQUEUE_H
#define DATA_STRUCTURE_CLNKQUEUE_H

struct LNode{
    int data;
    struct LNode *next;
};

typedef struct LNode CLnkqueue;


void CLQ_makeEmpty(CLnkqueue *q);

int CLQ_isEmpty(CLnkqueue *q);

int CLQ_Length(CLnkqueue *q);

void CLQ_In(CLnkqueue *q);

int CLQ_Out(CLnkqueue *q);

int CLQ_head(CLnkqueue *q);

void CLQ_Print(CLnkqueue *q);

#endif //DATA_STRUCTURE_CLNKQUEUE_H
