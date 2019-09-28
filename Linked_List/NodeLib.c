//
// Created by Apoiuty on 2019/9/2.
//

#include "NodeLib.h"

void PrintList(Node *head, AppendNewLine addnl) {
//    从头结点打印链表
    Node *cur = head;
    while (cur) {
        if (addnl == newLine) {
            printf("%d\n", cur->data);
        } else {
            printf("%d ", cur->data);
        }
        cur = cur->next;
    }
}

 int FindNode(Node *head, int x) {
//    查找链表中指定的元素
    Node *cur = head, *preNode;
    while (cur) {
        if (cur->data == x) {
            return 1;
        } else {
            preNode = cur;
            cur = cur->next;
        }
    }
    return 0;
}

void InsertFront(Node **head, int x) {
//    在头结点插入节点
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->
            next = *head;
    newNode->
            data = x;
    *head = newNode;
}

void DeleteAt(Node **head) {
//    删除单链表的头结点
    Node *p = *head;
    if (*head) {
        *head = (*head)->next;
        free(p);
    } else {
        printf("Delte failure.\n");
    }
}

void Delte(Node **head, int x) {
    Node *cur = *head, *pre = NULL;
    while (cur->data != x && cur) {
        pre = cur;
        cur = cur->next;
    }

    if (cur) {
        if (!pre) {
            *head = (*head)->next;
        } else {
            DeleteAfter(pre);
        }
        free(cur);
    }
}

void InsertOrder(Node **head, int x) {
//    在降序链表中插入节点
    Node *cur = *head, *pre, *newNode;
    pre = NULL;

    while (cur) {
        if (x < cur->data)
            break;
        pre = cur;
        cur = cur->next;
    }
    if (pre == NULL) {
        InsertFront(head, x);
    } else {
        newNode = (Node *) malloc(sizeof(Node));
        InsertAfter(pre, newNode);
    }
}

static void ClearList(Node **head){
    Node *cur=*head,*next=NULL;
    while (cur){
        next=cur->next;
        free(cur);
        cur=next;
    }
    head=NULL;
}