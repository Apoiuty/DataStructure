//
// Created by Apoiuty on 2019/8/29.
//

#ifndef DATA_STRUCTURE_STACK_H
#define DATA_STRUCTURE_STACK_H

#include <stdio.h>
#include <stdlib.h>

enum boolean {
    False, True
};

typedef enum boolean Bool;

typedef struct stack {
    int top;
    int MaxSize;
    int *Element;
} Stack;

void InitStack(Stack *S,int sz);

void FreeStack(Stack *S);

int Push(Stack *S,int x);

int pop(Stack *S);

int GetTop(Stack *S);

void Empty(Stack *S);

Bool isEmpty(Stack *S);

Bool isFull(Stack *S);

void EvaluatePostfix(char *s);

void Infix2Postfix(char *s);

void EvaluateInfix(char *s);


#endif //DATA_STRUCTURE_STACK_H
