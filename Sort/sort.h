//
// Created by Apoiuty on 2019/9/29.
//

#ifndef DATA_STRUCTURE_SORT_H
#define DATA_STRUCTURE_SORT_H
typedef struct forSort {
    int data;
} ForSort;

//基数排序数据结构, 假设排序码有三位
struct RSort {
    int key[3];
    struct RSort *next;
};

typedef struct RSort rsort;

//初始化记录
void Initialization(ForSort A[], int n);


//直接插入排序
void DirectInsertionSort(ForSort A[], int n);

//打印排序完的列表
void PrintSorted(ForSort A[], int n);

//折半插入排序
void BinaryInsertSort(ForSort A[], int n);

//选择排序
void DirectSelection(ForSort A[], int n);

//冒泡排序
void BubbleSort(ForSort A[], int n);

//快速排序
void QuickSort(ForSort A[], int low, int high);

//基数排序
void RadixSort(rsort *A, int low, int high, int d);

//归并排序
void MergeSort(ForSort *A, int n);


void OnePassMerge(ForSort *Dsc, ForSort *Src, int len, int n);

void TwoPassMerge(ForSort *Dsc, ForSort *Src, int s, int e1, int e2);

#endif //DATA_STRUCTURE_SORT_H
