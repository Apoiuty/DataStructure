//
// Created by Apoiuty on 2019/8/27.
//

#include "list.h"
#include <string.h>

void InitList(LinearList *L, int size) {
//    线性表初始化
    if (size) {
        L->Last = 0;
        L->Maxsize = size;
        L->data = (ElementType *) malloc(sizeof(ElementType) * L->Maxsize);
    }
}

void FreeList(LinearList *L) {
//  释放线性表
    free(L->data);
}

_Bool ListEmpty(LinearList *L) {
//    判断线性表是否为空
    return L->Last <= 0 ? 1 : 0;
}

_Bool ListFull(LinearList *L) {
//    判断线性表是否已满
    return L->Last >= L->Maxsize ? 1 : 0;
}

int ListLength(LinearList *L) {
//    return the length of linear list
    return L->Last;
}

ElementType GetItem(LinearList *L, int i) {
//
    return (ElementType) ((i < 0 || i >= L->Last) ? NULL : L->data[i]);
}

int LocateElem(LinearList *L, ElementType x) {
//    定位元素
    for (int i = 0; i < L->Last; ++i) {
        if (L->data[i] == x)
            return i;
    }
    return -1;
}

_Bool InsertElem(LinearList *L, ElementType x, int i) {
//    插入元素
    if (i < 0 || i > L->Last || L->Last == L->Maxsize)
        return false;
    else {
        for (int j = L->Last - 1; j >= i; j--) {
            L->data[j + 1] = L->data[j];
        }
        L->data[i] = x;
        L->Last++;
        return 1;
    }
}

_Bool DeleteElem(LinearList *L, int i) {
//    删除元素
    if (i < 0 || L->Last == 0 || i > L->Last)
        return false;
    else {
        for (int j = i; j < L->Last - 1; ++j) {
            L->data[j] = L->data[j + 1];
        }
        L->Last--;
        return true;
    }
}

void PrintOut(LinearList *L) {
    for (int i = 0; i < L->Last; ++i) {
        printf("%d ", L->data[i]);
    }
    printf("\n");
}

ElementType DeleteMin(LinearList *L) {
//  删除最小元素
    if (ListEmpty(L)) {
        printf("The List is empty.\n");
        exit(1);
    } else {
        int min = L->data[0], index = 0;
        for (int i = 1; i < L->Last; ++i) {
            if (L->data[i] < min) {
                min = L->data[i];
                index = i;
            }
        }
        L->data[index] = L->data[L->Last - 1];
        return min;
    }
}


void Reverse(LinearList *L) {
//    翻转线性表
    ElementType temp;
    for (int i = 0; i < L->Last / 2; ++i) {
        temp = L->data[i];
        L->data[i] = L->data[L->Last - i - 1];
        L->data[L->Last - i - 1] = temp;
    }
}


void del_x(LinearList *L, ElementType x) {
//    方法一
    int k = 0;
    for (int i = 0; i < L->Last; ++i) {
        if (L->data[i] != x)
            L->data[k++] = L->data[i];
    }
    L->Last = k;


    /*方法2*/
    k = 0;
    int i = 0;
    while (i < L->Last) {
        if (L->data[i] == x)
            k++;
        else {
            L->data[i - k] = L->data[i];
        }
    }
    L->Last = L->Last - k;
}

void del_s_t(LinearList *L, ElementType s, ElementType t) {
    if (s > t) {
        printf("s must be greater than t.\n");
        exit(1);
    }


    int k = 0;
    for (int i = 0; i < L->Last; ++i) {
        if (L->data[i] < s || L->data[i] > t)
            L->data[k++] = L->data[i];
    }
    L->Last = k;
}

void del_common(LinearList *L) {
    int k = 1, flag = 0;
    for (int i = 1; i < L->Last; ++i) {
        flag = 0;
//        前驱节点有重复flag为1
        for (int j = 0; j < i; ++j) {
            if (L->data[j] == L->data[i])
                flag = 1;
        }
        if (!flag)
            L->data[k++] = L->data[i];
    }
    L->Last = k;
}

LinearList *LinearList_Union(LinearList *La, LinearList *Lb) {
    LinearList *L = (LinearList *) malloc(sizeof(LinearList));
    InitList(L, La->Last + Lb->Last);

    int i, j, k;
    for (i = 0, j = 0, k = 0; i < La->Last && j < L->Last;) {
        if (La->data[i] < Lb->data[j]) {
            L->data[k++] = La->data[i++];
        } else
            L->data[k++] = L->data[j++];
    }

    if (j != Lb->Last - 1) {
        while (j < Lb->Last)
            L->data[k++] = Lb->data[j++];
    } else if (i != La->Last - 1) {
        while (i < La->Last)
            L->data[k++] = Lb->data[i++];
    }
    L->Last = k;
    return L;
}

void transfer_m_n(LinearList *A, int m, int n) {
    ElementType Temp[m];
    memcpy(Temp, A->data, sizeof(Temp));
    memcpy(A->data, A->data + m, sizeof(ElementType) * n);
    memcpy(A->data + m, Temp, sizeof(Temp));
}

void find_x(LinearList *L, int x) {
    int low = 0, high = L->Last, mid = 0, temp;

    while (low <= high) {
        mid = (low + high) / 2;
        if (L->data[mid] == x) {
            break;
        } else if (L->data[mid] > x)
            high = mid - 1;
        else
            low = mid + 1;
    }
    if (L->data[mid] == x && mid != L->Last - 2) {
        temp = L->data[mid];
        L->data[mid] = L->data[mid + 1];
        L->data[mid + 1] = temp;
    }
    if (low > high) {
        int i;
        for (i = L->Last - 1; i > high; i--)
            L->data[i + 1] = L->data[i];
        L->data[i + 1] = x;
    }
}

void Reverse_int(int *R, int m, int n) {
    int temp;
    for (int i = m, j = n; i < j; ++i, --j) {
        temp = R[i];
        R[i] = R[j];
        R[j] = temp;
    }
}

void Left_Shift(int *R, int p, int n) {
    Reverse_int(R, 0, p - 1);
    Reverse_int(R, p, n - 1);
    Reverse_int(R, 0, n - 1);
}

int Find_Midian(const int *S1, const int *S2, int n) {
//    复杂度为O(n)的算法
//    int midian, index = 0;
//    for (int i = 0, j = 0;; ) {
//        if (S1[i] <= S2[j]) {
//            midian = S1[i];
//            index++, i++;
//        } else if (S1[i] > S2[j]) {
//            midian = S2[j];
//            index++, j++;
//        }
//        if (index == n) {
//            break;
//        }
//
//    }
//    return midian;

//      复杂度为O(logn)的算法，因为是求中位数，很容易想到对元素除2
    int s1 = 0, m1, d1 = n - 1, s2 = 0, m2, d2 = n - 2;
    while (s1 != d1 || s2 != d2) {
        m1 = (s1 + d1) / 2;
        m2 = (s2 + d2) / 2;
        if (S1[m1] == S2[m2]) {
            return S1[m1];
        }
        if (S1[m1] < S2[m2]) {
            if ((s1 + d1) % 2 == 0) {
                s1 = m1, d2 = m2;
            } else {
                s1 = m1 + 1, d2 = m2;
            }
        }
        if (S1[m1] > S2[m2]) {
            if ((s1 + d1) % 2 == 0) {
                d1 = m1, s2 = m2;
            } else {
                d1 = m1, s2 = m2 + 1;
            }
        }
    }
    return S1[s1] < S2[s2] ? S1[s1] : S2[s2];

}

int Majority(int A[], int n) {
    int i, c, cnt = 1;
    c = A[0];
    for (i = 1; i < n; i++) {
        if (A[i] == c) {
            cnt++;
        } else {
            if (cnt > 0)
                cnt--;
            else {
                c = A[i];
                cnt = 1;
            }
        }
    }
    if (cnt) {
        for (i = cnt = 0; i < n; i++) {
            if (A[i] == c) {
                cnt++;
            }

        }
        if (cnt > n / 2)
            return c;
        else return -1;
    }
}

int Min_Positive(int *A, int n) {
    int *B, i;
    B = (int *) malloc(sizeof(int) * n);
    memset(B, 0, sizeof(int) * n);
    for (i = 0; i < n; i++) {
        if (A[i] > 0 && A[i] <= n)
            B[A[i] - 1] = 1;
    }
    for (i = 0; i < n; i++) {
        if (B[i] == 0)
            return i + 1;
    }
    return i + 1;
}