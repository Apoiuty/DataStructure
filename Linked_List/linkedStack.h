//
// Created by Apoiuty on 2019/9/21.
//

#ifndef DATA_STRUCTURE_LINKEDSTACK_H
#define DATA_STRUCTURE_LINKEDSTACK_H

#include "linkedlist.h"

//栈的链表实现
struct linkedStack {
    LinkedList *stack;
};

typedef struct linkedStack LinkedStack;

//初始化函数
void InitLinkedStack(LinkedStack *S);

//压栈操作
void PushLS(LinkedStack *S, int x);

//弹栈操作
int popLS(LinkedStack *S);

//返回栈顶元素
int Top(LinkedStack *S);


#endif //DATA_STRUCTURE_LINKEDSTACK_H
