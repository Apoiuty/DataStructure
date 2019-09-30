//
// Created by Apoiuty on 2019/9/29.
//

#include <stdlib.h>
#include <string.h>
#include "sort.h"
#include <stdio.h>
#include <time.h>

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
    srand(time(0));
    for (int i = 0; i < n; ++i) {
        A[i].data = rand() % n + 1;
    }
}

//打印排序完的列表
void PrintSorted(ForSort A[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", A[i].data);
    }

    printf("\n");
}

//折半插入排序
void BinaryInsertSort(ForSort A[], int n) {
//    采用折半插入排序对A进行排序, n为A的大小
//    无返回值

    int i, r, k;
    ForSort temp;

    for (i = 1; i < n; i++) {
        temp = A[i];
        k = 0;
        r = i - 1;
//        找出插入位置
        while (k <= r) {
            int m;
            m = (k + r) / 2;
            if (temp.data < A[m].data)
                r = m - 1;
            else {
                k = m + 1;
            }

        }
//          插入位置以后元素后移
        for (r = i; r > k; r--) {
            A[r] = A[r - 1];
        }
//          插入位置赋值
        A[k] = temp;
    }
}

//希尔排序
void ShellSorted(ForSort A[], int n, int s) {
//    分组的插入排序
    int i, j, k;
    ForSort temp;

//  每次迭代s值除2
    for (k = s; k > 0; k >> 1) {

//        分组排序
        for (i = s; i < n; i++) {
            temp = A[i];
            j = i - k;
//          组内排序
            while (j >= 0 && A[j].data > temp.data) {
                A[j + k] = A[j];
                j = j - k;
            }
            A[j + k] = temp;
        }

    }
}

//直接选择排序
void DirectSelection(ForSort A[], int n) {
    int i, min, j;
    ForSort temp;
    for (i = 0; i < n; i++) {
        temp = A[i];
        j = i;
        for (min = i + 1; min < n; ++min) {
            if (A[min].data < temp.data)
                j = min;
        }

        if (j != i) {
            A[i] = A[j];
            A[j] = temp;
        }
    }
}

//冒泡排序
//    A为排序数组, n为数组大小
void BubbleSort(ForSort A[], int n) {
    int i, j;
    int flag;
    ForSort temp;

    for (i = n - 1, flag = 1; i > 0 && flag; i--) {
//        清除交换位
        flag = 0;
        for (j = 0; j < i; j++) {
            if (A[j].data > A[j + 1].data) {
//                交换位置一
                flag = 1;
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}

//快速排序
void QuickSort(ForSort A[], int low, int high) {
//    快速排序
    int i, j;
    ForSort temp;

    if (low >= high)
        return;

    i = low;
    j = high;
    temp = A[i];
    while (i < j) {
//        找到比A[i]小的换到A[i]的位置
        while (i < j && A[j].data >= temp.data)
            j--;

        if (i < j)
            A[i++] = A[j];

//        找到比A[i]小的换到A[j]的位置
        while (i < j && A[i].data <= temp.data)
            i++;

        if (i < j) {
            A[j--] = A[i];
        }

    }

    A[i] = temp;
    QuickSort(A, low, --j);
    QuickSort(A, ++i, high);
}

//基数排序
void RadixSort(rsort A[], int low, int high, int d) {
//    基数排序, low为数据元素最小值, high为最大值, d为数据元素位数

//    r个存储空间
    typedef struct {
        rsort *pHead;
        rsort *pTail;
    } TempLink;

    int r = high - low + 1;
    int i, j, k;
    TempLink *tlink;
    rsort *p;
    tlink = (TempLink *) malloc(sizeof(TempLink) * r);

    for (i = d - 1; i >= 0; i--) {
//        r个数组初始化
        for (j = 0; j < r; j++) {
            tlink[j].pHead = tlink[j].pTail = NULL;
        }

//        将记录分配到r个数组
        for (p = A; p; p = p->next) {
            j = p->key[i] - low;
            if (tlink[j].pHead == NULL) {
                tlink[j].pHead = tlink[j].pTail = p;
            } else {
                tlink[j].pTail->next = p;
                tlink[j].pTail = p;
            }
        }

        j = 0;
        while (tlink[j].pHead == NULL && j < r) {
            j++;
        }

        A = tlink[j].pHead;
        p = tlink[j].pTail;

        for (k = j + 1; k < r; k++) {
            if (tlink[j].pHead) {
                p->next = tlink[k].pHead;
                p = tlink[k].pTail;
            }
            p->next = 0;
        }


    }
}

//归并排序
void MergeSort(ForSort *A, int n) {
    int k;
    ForSort *B = (ForSort *) malloc(sizeof(ForSort) * n);

    k = 1;
    while (k < n) {
//      A中子文件经过一趟合并到B
        OnePassMerge(B, A, k, n);
        k = k << 1;
        if (k < n) {
            OnePassMerge(A, B, k, n);
            k <<= 1;

        } else {
            memcpy(A, B, sizeof(ForSort) * n);
        }
    }
}

/**
 * 一趟归并函数
 * @param Dsc 目的
 * @param Src 源
 * @param len 子文件长度
 * @param n 源长度
 */
void OnePassMerge(ForSort *Dsc, ForSort *Src, int len, int n) {
    int i;
    for (i = 0; i < n - 2 * len; i += 2 * len) {
        TwoPassMerge(Dsc, Src, i, i + len - 1, i + 2 * len - 1);
    }

    if (i < n - len) {
        TwoPassMerge(Dsc, Src, i, i + len - 1, n - 1);
    } else {
        memcpy(Dsc, Src, sizeof(n - i));
    }
}

/**
 * 两两归并函数, 将Src中从s到e1和从e1+1到e2的子文件合并到Dsc
 * @param Dsc 目的
 * @param Src 源
 * @param s 第一个开始点
 * @param e1 第一个结束点
 * @param e2 第二个开始点
 */
void TwoPassMerge(ForSort *Dsc, ForSort *Src, int s, int e1, int e2) {
    int s1, s2;
    for (s1 = s, s2 = e1 + 1; s1 <= e1 && s2 <= e2;) {
        if (Src[s1].data < Src[s2].data) {
            Dsc[s++] = Src[s1++];
        } else
            Dsc[s++] = Src[s2++];

    }

    if (s1 <= e1) {
        memcpy(Dsc + s, Src + s1, (e1 - s1 + 1) * sizeof(ForSort));

    } else if (s2 <= e2)
        memcpy(Dsc + s, Src + s2, (e2 - s2 + 1) * sizeof(ForSort));
}