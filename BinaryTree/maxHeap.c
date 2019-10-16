//
// Created by Apoiuty on 2019/10/16.
//

#include "maxHeap.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 *
 * 求堆中元素个数
 * @param xheap
 * @return 个数
 */
int Size(MaxHeap *xheap) {
    return xheap->heapsize;
}


/**
 * 返回大根堆中堆顶元素
 * @param xheap 堆
 * @return 堆顶元素
 */
int Max(MaxHeap *xheap) {
    if (xheap->heapsize) {
        return xheap->heap[0];
    }
}


/**
 * 初始化大根堆
 * @param xheap
 */
void Init_MaxHeap(MaxHeap *xheap, int size) {
    xheap->Maxsize = size;
    xheap->heap = (int *) malloc(sizeof(int) * size);
    xheap->heapsize = 0;
}

/**
 * 在大根堆中插入一个元素
 * @param xheap
 * @param x
 */
void InsertHeap(MaxHeap *xheap, int x) {
    int i;
    if (xheap->heapsize == xheap->Maxsize) {
        printf("Overflow.\n");
        exit(1);
    }
    i = xheap->heapsize++;
    while (i && x > xheap->heap[(i - 1) / 2]) {
        xheap->heap[i] = xheap->heap[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    xheap->heap[i] = x;
}

/**
 * delte item of the heap top
 * @param xheap
 * @param x
 * @return 被删除的元素
 */
int DelteMax(MaxHeap *xheap, int *x) {
    int i = 0, ic = 1;
//    ic指向下一层中的最大子节点
    if (xheap->heapsize == 0) {
        printf("underflow.\n");
        exit(1);
    }

    *x = xheap->heap[0];
    int y = xheap->heap[--xheap->heapsize];
    while (ic < xheap->heapsize) {
        if ((ic + 1) < xheap->heapsize && xheap->heap[ic] < xheap->heap[ic + 1])
            ic += 1;
        if (y >= xheap->heap[ic]) {
            break;
        }

        xheap->heap[i] = xheap->heap[ic];

        i = ic;
        ic = 2 * ic + 1;
    }
    xheap->heap[i] = y;

    return *x;

}

/**
 * 创建大根堆
 * @param heap 根节点
 * @param a 数据
 * @param size 堆大小
 * @param Maxsize 堆上限
 */
void MakeHeap(MaxHeap *heap, int *a, int size, int Maxsize) {
    int i, ic;
    int y;
    free(heap->heap);

    heap->heap = (int *) malloc(sizeof(int) * size);
    memcpy(heap->heap, a, sizeof(int) * size);
    heap->heapsize = size;

    heap->Maxsize = Maxsize;
    for (i = (heap->heapsize - 2) / 2; i >= 0; i--) {
//        i指向父节点
        y = heap->heap[i];
//        ic为子节点
        ic = 2 * i + 1;
        while (ic < heap->heapsize) {
            if ((ic + 1) < heap->heapsize && heap->heap[ic] < heap->heap[ic + 1])
                ic++;
            if (y >= heap->heap[ic])
                break;

//          子节点大于父节点, 子节点上位
            heap->heap[(ic - 1) / 2] = heap->heap[ic];
            ic = 2 * ic + 1;
        }
//        安置父节点
        heap->heap[(ic - 1) / 2] = y;
    }
}

/**
 * 判断一个完全二叉树列表是不是大根堆
 * @param A 列表
 * @return 逻辑值
 * @param n 数组大小
 */
int IsMaxHeap(int A[], int n) {

    for (int i = (n - 2) / 2; i >= 0; --i) {
//        如果有右子树
        if (2 * i + 2 < n)
//            孩子大于父亲
        {
            if (A[2 * i + 1] > A[i] || A[2 * i + 2] > A[i])
                return 0;
        } else {
            if (A[2 * i + 1] > A[i]) {
                return 0;
            }
        }
    }

    return 1;
}

