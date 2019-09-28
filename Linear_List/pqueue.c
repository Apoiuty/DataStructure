//
// Created by Apoiuty on 2019/8/31.
//

#include "pqueue.h"
#include <stdio.h>
#include <stdlib.h>

void InitPqueue(Pqueue *P) {
    P->cnt = 0;
}

int PQdelete(Pqueue *P) {
    int min;
    int minindex = 0;

    if (P->cnt > 0) {
        min = P->pqlist[0];
        for (int i = 0; i < P->cnt; ++i) {
            if (P->pqlist[i] < min) {
                min = P->pqlist[i];
                minindex = i;
            }
        }
        P->pqlist[minindex] = P->pqlist[--P->cnt];
    } else {
        printf("Delete from an empty priority.\n");
        exit(1);
    }
    return min;
}

void InsertPqueue(Pqueue *P, int item) {
    if (P->cnt == MAXPSZIE) {
        printf("Queue is full.\n");
        exit(1);
    } else {
        P->pqlist[P->cnt++] = item;
    }
}

int PQEmpty(Pqueue *P) {
    return P->cnt == 0;
}

int PQFull(Pqueue *P) {
    return P->cnt == MAXPSZIE;
}

