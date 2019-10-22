//
// Created by Apoiuty on 2019/10/22.
//

#include "find.h"

/**
 * 顺序查找
 * @param A 顺序表
 * @param key 关键码
 * @param n 顺序表长度
 * @return 返回下标或者-1(未找到)
 */
int SeqSearch(const int A[], int key, int n) {
    for (int i = 0; i < n; ++i) {
        if (A[i] == key)
            return i;
    }
    return -1;
}


/**
 * 二分查找
 * @param A 要查找的数组
 * @param key 关键码
 * @param n 数组大小
 * @return 索引值
 */
int BinarySearch(const int A[], int key, int n) {
    int low, high, mid;

    low = 0, high = n - 1;
    while (low <= high) {
        mid = (high - low) / 2;
        if (A[mid] == key)
            return mid;
        else {
            if (A[mid] < key) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }
    return -1;
}


int Hash(int key) {
    return 0;
}

/**
 * 哈希散列查找
 * @param A
 * @param key
 * @param n
 */
int HashSearch(int *A, int key, int n) {
    int cnt;
    int k = Hash(key);
    cnt = 0;
    while (cnt < n && A[k] != key && A[k] != 0) {
        if (++k > n)
            k = 0;
        cnt++;
    }

    if (cnt == n) {
        printf("Hash table is overflowed.\n");
        return -1;
    } else if (A[k] == key)
        return k;
    else {
        A[k] = key;
        return -1;
    }

}

int Hash2(int key) {
    return 0;
}

int Hash1(int key) {
    return 0;
}

/**
 * 哈希散列查找
 * @param A
 * @param key
 * @param n
 */
int DHashSearch(int *A, int key, int n) {
    int cnt = 0;
    int k = Hash1(key);
    int c = Hash2(key);
    while (cnt < n && A[k] != key && A[k] != 0) {
        k += c;
        k %= n;
        cnt++;
    }

    if (cnt == n) {
        printf("Hash table is overflowed.\n");
        return -1;
    } else if (A[k] == key)
        return k;
    else {
        A[k] = key;
        return -1;
    }
}