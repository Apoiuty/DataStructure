//
// Created by Apoiuty on 2019/8/27.
//

#ifndef DATA_STRUTURE_LIST_H
#define DATA_STRUTURE_LIST_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct linearList LinearList;
typedef int ElementType;


struct linearList {
    ElementType *data;
    int Maxsize;
    int Last;
};



void InitList(LinearList *L, int size);

void FreeList(LinearList *L);

_Bool ListEmpty(LinearList *L);

_Bool ListFull(LinearList *L);

int ListLength(LinearList *L);

ElementType GetItem(LinearList *L, int i);

int LocateElem(LinearList *L, ElementType x);

_Bool InsertElem(LinearList *L, ElementType x, int i);

_Bool DeleteElem(LinearList *L, int i);

void PrintOut(LinearList *L);

ElementType DeleteMin(LinearList *L);

void Reverse(LinearList *L);

void del_x(LinearList *,ElementType x);


void del_s_t(LinearList *,ElementType s,ElementType t);

void del_common(LinearList *L);

LinearList *LinearList_Union(LinearList *La,LinearList *Lb);

void transfer_m_n(LinearList *A, int m, int n);

void find_x(LinearList *L, int x);

void Reverse_int(int *R, int m, int n);

void Left_Shift(int *R, int p, int n);

int Find_Midian(const int *S1, const int *S2, int n);


int Majority(int A[], int n);

int Min_Positive(int *A, int n);
#endif //DATA_STRUTURE_LIST_H
