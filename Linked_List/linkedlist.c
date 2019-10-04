//
// Created by Apoiuty on 2019/9/2.
//

#include <time.h>
#include "linkedlist.h"


//初始化链表
void InitLinkedList(LinkedList *L) {
    L->rear = 0;
    L->front = 0;
    L->cur = 0;
    L->pre = 0;
    L->pos = -1;
    L->size = 0;
}

int IsEmptyList(LinkedList *L) {
    return L->size == 0;
}

int NextNode(LinkedList *L) {
    if (L->pos >= 0 || L->pos < L->size) {
        L->pos++;
        L->pre = L->cur;
        L->cur = (L->cur)->next;
    } else
        L->pos = L->size;
    return L->pos;
}

int SetPos(LinkedList *L, int pos) {
    if (L->size == 0)
        return -1;
    if (pos < 0 || pos > L->size - 1)
        return -1;

    L->cur = L->front;
    L->pre = NULL;
    L->pos = 0;

    for (int i = 0; i < pos; ++i) {
        L->pos++;
        L->pre = L->cur;
        L->cur = (L->cur)->next;
    }
    return L->pos;
}

//链表中当前位置插入新节点的函数
void InsertAt(LinkedList *L, int x) {
    Node *newnode;
    if (!L->size) {
        newnode = Get_Node(L->front, x);
        L->front = L->rear = newnode;
    } else if (L->size == 1) {
        newnode = Get_Node(L->front, x);
        L->front = newnode;
    } else {
        newnode = Get_Node(L->cur, x);
        InsertAfter(L->pre, newnode);
    }
    L->size++;
    L->cur = newnode;
}

void InsertLAfter(LinkedList *L, int x) {
    Node *newNode;
    if (L->size == 0) {
        newNode = Get_Node(NULL, x);
        L->front = L->rear = newNode;
        L->pos = 0;
    } else if (L->cur == L->rear || !L->cur) {
        newNode = Get_Node(NULL, x);
        InsertAfter(L->rear, newNode);
        L->pre = L->rear;
        L->rear = newNode;
        L->pos++;
    } else {
        newNode = Get_Node(L->cur->next, x);
        InsertAfter(L->cur, newNode);
        L->pre = L->cur;
        L->pos++;
    }
    L->size++;
    L->cur = newNode;
}

void DeleteAT(LinkedList *L) {
    Node *oldNode;
    if (!L->cur) {
        printf("Invalid position.\n");
        exit(1);
    }
    if (!L->pre) {
        oldNode = L->front;
        L->front = L->cur->next;
    } else
        oldNode = DeleteAfter(L->pre);
    if (oldNode == L->rear) {
        L->rear = L->pre;
    }
    L->cur = oldNode->next;
    L->size--;
}

int GetData(LinkedList *L) {
    if (L->size > 0 && L->pos < L->size)
        return L->cur->data;
    else {
        printf("Invalid position.\n");
        exit(1);
    }
}

void SetData(LinkedList *L, int x) {
    if (!L->size || !L->cur) {
        printf("Invalid Positon.\n");
        exit(1);
    } else
        L->cur->data = x;
}

void ClearLinkedList(LinkedList *L) {
    Node *cur = L->front, *nextNode;
    while (cur) {
        nextNode = cur->next;
        free(cur);
        cur = nextNode;
    }
    L->front = L->cur = L->rear = L->pre = NULL;
    L->pos = -1;
}

void DelteLAfter(LinkedList *L) {
    Node *oldnode;
//    被删除的节点
    if (!L->cur || L->rear == L->cur) {
        printf("Current position is invalid.\n");
//        空节点或者尾节点则打印错误信息
    } else {
        oldnode = DeleteAfter(L->cur);
//        oldnode为尾节点
        if (oldnode == L->rear) {
            L->rear = L->cur;
        }
        free(oldnode);
        L->size--;
    }
}

//打印链表
void PrintOutL(Node *head) {
    Node *cur = head->next;
    while (cur) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

//创建长度为N的链表
Node *CreatL(int n) {
    srand(time(0));
    Node *head = (Node *) malloc(sizeof(Node));
    head->next = NULL;

    Node *cur = head, *new;
    for (int i = 0; i < n; ++i) {
        new = (Node *) malloc(sizeof(Node));
        new->data = rand() % n + 1;
        new->next = NULL;
        cur->next = new;
        cur = new;
    }

    return head;


}