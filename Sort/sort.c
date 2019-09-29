//
// Created by Apoiuty on 2019/9/29.
//

#include <stdlib.h>
#include "sort.h"
#include <stdio.h>

//直接插入排序
void DirectInsertionSort(ForSort A[], int n) {
    int i, j;
    ForSort temp;

    for (i = 1; i < n; ++i) {
        temp = A[i];
        j = i - 1;
        while (A[j].data > temp.data && j >= 0) {
            A[j + 1] = A[j];
            j--;
        }

        A[j + 1].data = temp.data;
    }
}

//初始化记录
void Initialization(ForSort A[], int n) {
    for (int i = 0; i < n; ++i) {
        A[i].data = rand() % n + 1;
    }
}

//打印排序完的列表
void PrintSorted(ForSort A[], int n) {
    for (int i = 0; i <n ; ++i) {
        printf("%d ", A[i].data);
    }

    printf("\n");
}