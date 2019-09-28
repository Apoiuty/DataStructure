//
// Created by Apoiuty on 2019/8/27.
//

#include "vector.h"
#include <stdio.h>
#include <stdlib.h>

void InitVector(Vector *V, int sz) {
    if (sz <= 0)
        printf("sz must be positive.");
    else {
        V->ArraySize = sz;
        V->VectorLength = 0;
        GetArray(V);
    }
}

void GetArray(Vector *V) {
    V->elem = (ElementType *) malloc(sizeof(ElementType) * V->ArraySize);
    if (V->elem == NULL) {
        printf("Memory allocation failed.\n");

    }
}

ElementType GetNode(Vector *V, int i) {
    if (i < 0 || i >= V->VectorLength)
        printf("Wrong Index.\n");
    else
        return V->elem[i];
}

void FreeVector(Vector *V) {
    free(V->elem);
}

int Find(Vector *V, ElementType x) {
    for (int i = 0; i < V->VectorLength; ++i) {
        if (x == V->elem[i])
            return 1;
    }
    return 0;
}

int Remove(Vector *V, int i) {
    if (V->VectorLength == 0) {
        printf("Vector is empty.\n");
        return 0;
    } else if (i < 0 || i > V->VectorLength) {
        printf("Wrong index.\n");
        return 0;
    } else
        for (int j = i; j < V->VectorLength - 1; ++j) {
            V->elem[j] = V->elem[j + 1];
            V->VectorLength--;
            return 1;
        }

}

int Insert(Vector *V, ElementType x, int i) {
    if (V->VectorLength == V->ArraySize)
        return 0;
    else if (i < 0 || i > V->VectorLength) {
        printf("Wrong Index.\n");
        return 0;
    } else {
        for (int j = V->VectorLength - 1; j >= i; --j) {
            V->elem[j + 1] = V->elem[j];
        }
        V->elem[i] = x;
        V->VectorLength++;
        return 1;
    }
}

Vector *Union(Vector *Va, Vector *Vb) {
    Vector *Vc = (Vector *) malloc(sizeof(Vector));
    int m = Va->VectorLength, n = Vb->VectorLength;
    InitVector(Vc, m + n);

    int index = 0;
    for (int i = 0; i < m; ++i) {
        Insert(Vc, Va->elem[i], i);
        index++;
    }
    for (int j = 0; j < n; ++j) {
        if (!Find(Va, Vb->elem[j]))
            Insert(Vc, Vb->elem[j], index), index++;

    }
    return Vc;
}

Vector *Intersection(Vector *Va, Vector *Vb) {
    Vector *Vc = (Vector *) malloc(sizeof(Vector));
    int m = Va->VectorLength, n = Vb->VectorLength;
    InitVector(Vc, m > n ? n : m);
    int index = 0;
    for (int i = 0; i < m; i++) {
        if (Find(Vb, Va->elem[i]))
            Insert(Vc, Va->elem[i], index++);
    }
    return Vc;
}

void PrintOut_Vector(Vector *L) {

    for (int i = 0; i < L->VectorLength; ++i) {
        printf("%d ", L->elem[i]);
    }
    printf("\n");
}

void Josephus(Vector *p, int n, int s, int m) {
    int k = 1;
    for (int i = 0; i < n; ++i) {
        Insert(p, k, i);
        k++;
    }

    int s1 = s, w;
    for (int j = n; j >= 1; --j) {
        s1 = (s1 + m - 1) % j;
        if (s1 == 0)
            s1 = j;
        w = GetNode(p, s1 - 1);
        Remove(p, s1 - 1);
        Insert(p, w, n - 1);
    }
}
