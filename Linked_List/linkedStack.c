//
// Created by Apoiuty on 2019/9/21.
//

#include "linkedStack.h"

//初始化函数
void InitLinkedStack(LinkedStack *S) {
    S->stack = (LinkedList *) malloc(sizeof(LinkedList));
    InitLinkedList(S->stack);
}

//压栈操作
void PushLS(LinkedStack *S, int x) {
    InsertAt(S->stack, x);
}

//弹栈操作
int popLS(LinkedStack *S) {
    if (IsEmptyList(S->stack)) {
        printf("Stack is empty.\n");
        exit(1);
    } else {
        int temp = GetData(S->stack);
        DeleteAT(S->stack);
        return temp;
    }
}


//返回栈顶元素
int Top(LinkedStack *S) {
    if (IsEmptyList(S->stack)) {
        printf("Stack is empty.\n");
        exit(1);
    } else {
        return GetData(S->stack);
    }
}

