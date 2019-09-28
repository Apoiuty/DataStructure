//
// Created by Apoiuty on 2019/8/31.
//

#ifndef DATA_STRUCTURE_PQUEUE_H
#define DATA_STRUCTURE_PQUEUE_H


#define MAXPSZIE 50

typedef struct pqueue {
    int cnt;
    int pqlist[MAXPSZIE];
} Pqueue;

void InitPqueue(Pqueue *P);

void InsertPqueue(Pqueue *P,int item);

int PQdelete(Pqueue *P);

int PQEmpty(Pqueue *P);

int PQFull(Pqueue *P);


#endif //DATA_STRUCTURE_PQUEUE_H
