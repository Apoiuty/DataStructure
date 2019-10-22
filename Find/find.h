//
// Created by Apoiuty on 2019/10/22.
//

#ifndef DATA_STRUCTURE_FIND_H
#define DATA_STRUCTURE_FIND_H

#include <stdio.h>


/**
 * 顺序查找
 * @param A 顺序表
 * @param key 关键码
 * @param n 顺序表长度
 * @return 返回下标或者-1(未找到)
 */
int SeqSearch(const int A[], int key, int n);

/**
 * 二分查找
 * @param A 要查找的数组
 * @param key 关键码
 * @param n 数组大小
 * @return 索引值
 */
int BinarySearch(const int A[], int key, int n);

/**
 * 哈希散列查找
 * @param A
 * @param key
 * @param n
 */
int HashSearch(int *A, int key, int n);


/**
 * 哈希散列查找
 * @param A
 * @param key
 * @param n
 */
int DHashSearch(int *A, int key, int n);

#endif //DATA_STRUCTURE_FIND_H
