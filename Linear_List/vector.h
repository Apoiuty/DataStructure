//
// Created by Apoiuty on 2019/8/27.
//

#ifndef DATA_STRUTURE_VECTOR_H
#define DATA_STRUTURE_VECTOR_H
typedef int ElementType;
struct vector {
    ElementType *elem;
    int ArraySize;
    int VectorLength;
};

typedef struct vector Vector;

void GetArray(Vector *);

void InitVector(Vector *, int sz);

ElementType GetNode(Vector *, int i);

void FreeVector(Vector *);

int Find(Vector *,ElementType x);

int Remove(Vector *,int i);

int Insert(Vector *V,ElementType x,int i);

Vector *Union(Vector *,Vector *);
//向量求并运算

Vector *Intersection(Vector *Va,Vector *Vb);


//向量求交运算

void PrintOut_Vector(Vector *L) ;

void Josephus(Vector *p,int n,int s,int m);
#endif //DATA_STRUTURE_VECTOR_H
