//
// Created by Apoiuty on 2019/10/16.
//

#ifndef DATA_STRUCTURE_MAXHEAP_H
#define DATA_STRUCTURE_MAXHEAP_H

struct maxHeap {
    int heapsize, Maxsize;
    int *heap;
};

typedef struct maxHeap MaxHeap;

/**
 * 求堆中元素个数
 * @param xheap
 * @return 个数
 */
int Size(MaxHeap *xheap);

/**
 * 返回大根堆中堆顶元素
 * @param xheap 堆
 * @return 堆顶元素
 */
int Max(MaxHeap *xheap);

/**
 * 初始化大根堆
 * @param xheap
 */
void Init_MaxHeap(MaxHeap *xheap, int size);

/**
 * 在大根堆中插入一个元素
 * @param xheap
 * @param x
 */
void InsertHeap(MaxHeap *xheap, int x);

/**
 * delte item of the heap top
 * @param xheap
 * @param x
 * @return 被删除的元素
 */
int DelteMax(MaxHeap *xheap, int *x);

/**
 * 创建大根堆
 * @param heap 根节点
 * @param a 数据
 * @param size 堆大小
 * @param Maxsize 堆上限
 */
void MakeHeap(MaxHeap *heap, int *a, int size, int Maxsize);

/**
 * 判断一个完全二叉树列表是不是大根堆
 * @param A 列表
 * @return 逻辑值
 */
int IsMaxHeap(int A[], int n);

#endif //DATA_STRUCTURE_MAXHEAP_H
