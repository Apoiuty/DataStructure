//
// Created by Apoiuty on 2019/9/29.
//

#ifndef DATA_STRUCTURE_SORT_H
#define DATA_STRUCTURE_SORT_H
typedef struct forSort {
    int data
} ForSort;

//初始化记录
void Initialization(ForSort A[],int n);


//直接插入排序
void DirectInsertionSort(ForSort A[],int n);

//打印排序完的列表
void PrintSorted(ForSort A[], int n);
#endif //DATA_STRUCTURE_SORT_H
