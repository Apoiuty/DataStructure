//
// Created by Apoiuty on 2019/10/3.
//

#include "sort.h"
#include "../Linked_List/linkedlist.h"
#include <stdio.h>

#ifndef DATA_STRUCTURE_WANGDAO7_H
#define DATA_STRUCTURE_WANGDAO7_H

/**
 * 二路冒泡排序, 最小值前移, 最大值后移
 * @param A 待排序数组
 */
void TwoDirectionBubble(ForSort *A, int n);

/**
 * 把数组A的奇数元素放到偶数元素之前
 * @param A 待处理数组
 * @param n 数组大小
 */
void ChangeOddEven(ForSort A[], int n);

/**
 * 用快排的方法查找A中第k个元素(从小到大)
 * @param A 查找的数组
 * @param low 数组开始
 * @param high 数组结尾
 * @param k 查找的元素
 */
int Find_kth(ForSort A[], int low, int high, int k);

/**
 * 将A分为两个集合令|S1-S2|最大
 * @param A
 */
void SetPartition(ForSort A[], int n);

/**
 * 荷兰国旗问题, 将含有三种颜色的条状序列排序好
 * @param A 待排序数组
 * @param n 数组大小
 */
void Flag_Arrange(ForSort A[], int n);

/**
 * 单链表二路归并
 * @param head 带头结点的链表
 */
void MergeSortL(Node *head, int k);

#endif //DATA_STRUCTURE_WANGDAO7_H
