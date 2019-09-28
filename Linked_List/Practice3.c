//
// Created by Apoiuty on 2019/9/22.
//

#include "Practice3.h"
#include "cnode.h"
#include <math.h>

//将节点p开始的链表复制到链表list的尾部
void Append(Node *p, Node *list) {
    while (list->next) {
        list = list->next;
    }
    list->next = p;
}

//Josephus问题用循环链表解决
void Josephus2(int n, int s, int m) {
    CNode *head, *cur, *pre, *new;
    head = (CNode *) malloc(sizeof(CNode));
    InitCNode(head, 1);
    cur = head;

//    创建1到n的循环链表
    for (int i = 2; i <= n; ++i) {
        new = (CNode *) malloc(sizeof(CNode));
        InitCNode(new, i);
        InsertCNAfter(cur, new);
        cur = new;
    }

//    当前位置移动到s个人
    pre = cur;
    cur = head;
    for (int j = 1; j < s; ++j) {
        pre = cur;
        cur = cur->next;
    }

//    开始报数
    for (int k = 0; k < n; ++k) {
        for (int i = 1; i < m; ++i) {
            pre = cur;
            cur = cur->next;
        }
        printf("%d ", cur->data);
        if (cur->next != cur)
            cur = DeleteCNAfter(pre)->next;
        else
            break;
    }
}

//单链表翻转
void InverseLinkedList(LinkedList *L) {
    Node *pre, *cur, *next;
    pre = NULL, cur = L->front;
    while (cur) {
//      翻转链表中间的指针域
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
//  交换头尾节点
    Node *temp = L->front;
    L->front = L->rear, L->rear = temp;
}

//删除大于m小于M的元素
void Delete_n2M(LinkedList *L, int m, int M) {
    Node *pre, *cur, *mNode, *Mnode;

//    查找左边界节点
    cur = L->front;
    pre = NULL;
    while (cur) {
        if (cur->data > m)
            break;
        else {
            pre = cur;
            cur = cur->next;
        }
    }
    mNode = pre;

    //    查找右边界节点
    cur = L->front;
    pre = NULL;
    while (cur) {
        if (cur->data >= M)
            break;
        else
            cur = cur->next;
    }
    Mnode = cur;

//    是否从开始节点开始
    if (mNode != NULL) {
        cur = mNode->next;
    } else {
        cur = L->front;
    }

//    释放节点
    while (cur != Mnode) {
        pre = cur;
        cur = cur->next;
        free(pre);
    }

//    连接节点
    if (mNode) {
        mNode->next = Mnode;
    } else {
        L->front = Mnode;
    }

}

void Polynomial(void) {
    term *new, *head, *cur, *temp;
    head = (term *) malloc(sizeof(term));
    head->next = head->pre = NULL;

//    读入系数和幂次
    while (1) {
        new = (term *) malloc(sizeof(term));
        scanf("%lf %d", &(new->coeff), &(new->power));
        if (new->power == 0 && new->coeff == 0)
            break;
//        head成了一个空节点

        if (head->next) {
//            找到插入位置
            term *pre;
            temp = head->next;
            while (temp) {
                if (temp->power <= new->power) {
                    break;
                } else {
                    pre = temp;
                    temp = temp->next;
                }
            }

//          插入位置在中间
            if (temp != NULL) {
                new->pre = temp->pre;
                new->next = temp;
                temp->pre->next = new;
                temp->pre = new;
            } else {
//                插入位置在最后
                pre->next = new;
                new->pre = pre;
                new->next = NULL;
            }
        } else {
//            插入位置在表头
            head->next = new;
            new->pre = head;
            new->next = NULL;
        }
    }

//    打印多项式
    cur = head->next;
    while (cur) {
        if (cur == head->next)
            printf("%.2fx^%d", cur->coeff, cur->power);
        else
            printf("%+.2fx^%d", cur->coeff, cur->power);
        cur = cur->next;
    }

    double input;
    double sum;
    while (1) {
        printf("x: \n");
        scanf("%lf", &input);
        if (input == 0)
            break;
        else {
            sum = 0;
            cur = head->next;
            while (cur) {
                sum += cur->coeff * pow(input, cur->power);
                cur = cur->next;
            }
            printf("%.2lf\n", sum);
        }
    }
}

DNode *Sort(LinkedList *L) {
    DNode *mid, *pos_ptr, *neg_ptr, *new;
    mid = (DNode *) malloc(sizeof(DNode));
    InitDNode(mid, 0);
    pos_ptr = neg_ptr = mid;

    Node *cur = L->front;
    while (cur) {
        if (cur->data > 0) {
            new = (DNode *) malloc(sizeof(DNode));
            InitDNode(new, cur->data);
            InsrtDNAfter(pos_ptr, new);
            pos_ptr = new;
        } else if (cur->data < 0) {
            new = (DNode *) malloc(sizeof(DNode));
            InitDNode(new, cur->data);
            InsrtDNBefore(neg_ptr, new);
            neg_ptr = new;
        } else {
            new = (DNode *) malloc(sizeof(DNode));
            InitDNode(new, cur->data);
            InsrtDNBefore(mid, new);
        }
        cur = cur->next;

    }

//    删除最初节点

    DeleteDNAT(mid);

    return neg_ptr;

}