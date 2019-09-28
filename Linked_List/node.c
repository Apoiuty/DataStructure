//
// Created by Apoiuty on 2019/9/1.
//

#include "node.h"

void InitNode(Node *N, int item, Node *ptr) {
    N->data = item;
    N->next = ptr;
//  ptr为下一个节点
}

void InsertAfter(Node *N, Node *p) {
//    N后添加p节点
    p->next = N->next;
    N->next = p;
}

Node *DeleteAfter(Node *N) {
//    删除节点N的后继节点, 返回被删除的节点
//    N ptr
    Node *ptr = N->next;
    if (ptr == NULL)
        return NULL;
    else {
        N->next = ptr->next;
        return ptr;
    }
}

Node *Get_Node(Node *N, int x) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    InitNode(newNode, x, N);
    return newNode;
}

void FreeNode(Node *ptr) {
//    释放节点
    if (ptr)
        free(ptr);
    else {
        printf("Ptr is Null.\n");
        exit(1);
    }

}

