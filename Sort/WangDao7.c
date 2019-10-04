//
// Created by Apoiuty on 2019/10/3.
//

#include "WangDao7.h"

/**
 * 二路冒泡排序, 最小值前移, 最大值后移
 * @param A 待排序数组
 * @param n 数组大小
 */
void TwoDirectionBubble(ForSort *A, int n) {
    int flag = 1;
//    奇排序还是偶排序
    int i, j, index;
    i = 0, j = n - 1;

    ForSort temp;

    for (; i < j;) {
        if (flag) {
//            如果flag为1, 那么把最小值移到最前
            for (index = j; index > i; index--) {
                if (A[index].data < A[index - 1].data) {
                    temp = A[index];
                    A[index] = A[index - 1];
                    A[index - 1] = temp;
                }
            }

            i++;
            flag = 0;
        } else {
//            如果flag==0把最大值移到后面
            for (index = i; index < j; index++) {
                if (A[index].data > A[index + 1].data) {
                    temp = A[index];
                    A[index] = A[index + 1];
                    A[index + 1] = temp;
                }
            }

            j--;
            flag = 1;
        }
    }
}

/**
 * 把数组A的奇数元素放到偶数元素之前
 * @param A 待处理数组
 * @param n 数组大小
 */
void ChangeOddEven(ForSort A[], int n) {
    int i = 0, j = n - 1;
    ForSort temp;


    while (i < j) {
//        从后向前搜索一个奇数
        while (A[j].data % 2 == 0)
            j--;
//        从前向后搜索一个偶数
        while (A[i].data % 2)
            i++;

//        交换
        if (i < j) {
            temp = A[j];
            A[j] = A[i];
            A[i] = temp;
            i++, j--;
        }

    }

}

int Find_kth(ForSort A[], int low, int high, int k) {
    int low_temp = low, high_temp = high;

    int temp = A[low].data;
    while (low < high) {
//        从后向前查找第一个小于temp的元素
        while (low < high && A[high].data >= temp) {
            high--;
        }

        A[low] = A[high];

        //        从前向后查找第一个大于temp的元素
        while (low < high && A[low].data <= temp) {
            low++;
        }

        A[high] = A[low];

    }

    if (low == k)
        return A[k].data;
    else if (low > k) {
        return Find_kth(A, low_temp, low - 1, k);
    } else {
        return Find_kth(A, low + 1, high_temp, k);
    }

}

/**
 * 将A分为两个集合令|S1-S2|最大
 * @param A
 * @param n
 */
void SetPartition(ForSort A[], int n) {
    int mid = n / 2;
    Find_kth(A, 0, n - 1, mid);
    printf("S1:\n");

    PrintSorted(A, mid);

    printf("S2:\n");

    PrintSorted(&A[mid], n - mid);

    PrintSorted(A, n);


}


/**
 * 荷兰国旗问题, 将含有三种颜色的条状序列排序好
 * @param A 待排序数组
 * @param n 数组大小
 */
void Flag_Arrange(ForSort A[], int n) {
    int head = 0, rear = n - 1;
    struct forSort temp;
    for (int i = 0; i <= rear; ++i) {
        switch (A[i].data % 3) {
            case 0:
                temp = A[i];
                A[i] = A[head];
                A[head++] = temp;
                break;
            case 2:
                temp = A[i];
                A[i] = A[rear];
                A[rear--] = temp;
                break;
        }
    }
}

/**
 * 单链表二路归并
 * @param head 带头结点的链表
 */
void MergeSortL(Node *head, int k) {
    Node *n1, *n2;
    Node *tHead, *new, *rear;
    tHead = (Node *) malloc(sizeof(Node));
//    tHead为临时存储空间
    tHead->next = NULL;
    rear = tHead;
    int i, temp;

//    空表直接退出
    if (head->next == NULL) {
        return;
    }

//    从从开始对链表中所有元素进行二路归并
    n1 = head->next;
    while (n1) {
//        找到n1对应的归并位置
        n2 = n1;
        i = 0;
        while (n2 && i < k) {
            n2 = n2->next;
            i++;
        }

//        归并
        if (n2) {
            int j1 = 0, j2 = 0;
            for (; j2 < k && j1 < k && n2;) {
                new = (Node *) malloc(sizeof(Node));
                if (n1->data > n2->data) {
                    new->data = n2->data;
                    new->next = NULL;
                    rear->next = new;
                    rear = new;
                    n2 = n2->next;
                    j2++;
                } else {
                    new->data = n1->data;
                    new->next = NULL;
                    rear->next = new;
                    rear = new;
                    n1 = n1->next;
                    j1++;
                }
            }

//            如果还有剩下的


            while (j1 < k) {
                new = (Node *) malloc(sizeof(Node));
                new->data = n1->data;
                new->next = NULL;
                rear->next = new;
                rear = new;
                n1 = n1->next;
                j1++;
            }

            while (j2 < k && n2) {
                new = (Node *) malloc(sizeof(Node));
                new->data = n2->data;
                new->next = NULL;
                rear->next = new;
                rear = new;
                n2 = n2->next;
                j2++;
            }
        } else if (n1 == head->next) {
            return;
//            k过大,说明已经归并完成
        }

//        下一组归并
        i = 0;
        while (n1 && i < k) {
            n1 = n1->next;
            i++;
        }

    }

//    数据转移
    n1 = head->next;
    n2 = tHead->next;
    while (n1 && n2) {
        n1->data = n2->data;
        n1 = n1->next;
        n2 = n2->next;
    }

//    释放tHead空间
    n2 = tHead;
    while (n2) {
        n1=n2->next;
        free(n2);
        n2 = n1;
    }

//    归并一趟后增大k
    k = k * 2;
    PrintOutL(head);
    MergeSortL(head, k);

}