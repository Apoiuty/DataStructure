//
// Created by Apoiuty on 2019/8/29.
//

#include "stack.h"
#include <string.h>
#include <stdio.h>

void InitStack(Stack *S, int sz) {
    S->MaxSize = sz;
    S->Element = (int *) malloc(sizeof(int) * S->MaxSize);
    S->top = -1;
}

void FreeStack(Stack *S) {
    free(S->Element);
}

int Push(Stack *S, int x) {
    if (S->top < S->MaxSize - 1) {
        S->top++;
        S->Element[S->top] = x;
        return True;
    } else
        return False;
}

void Empty(Stack *S) {
    S->top = -1;
}

int GetTop(Stack *S) {
    if (S->top > -1)
        return S->Element[S->top];
    else {
        printf("Stack is empty.\n");
        return -1;
    }
}

int pop(Stack *S) {
    if (S->top > -1) {
        return S->Element[S->top--];
    } else {
        printf("Stack is empty.\n");
        return -1;
    }
}

Bool isEmpty(Stack *S) {
    return (Bool) (S->top == -1);
}

Bool isFull(Stack *S) {
    return (Bool) (S->top == S->MaxSize - 1);
}

void Infix2Postfix(char *s) {
    Stack *Sptr = (Stack *) malloc(sizeof(Stack));
    InitStack(Sptr, 20);
    char buf[80];

    char *i = s;
    int j = 0;
    char temp;

    while (1) {
        if (strchr("0123456789", *i) && *i)
            buf[j++] = *i;
        else {
            if (strchr("+-*/()", *i) && *i)
                if (strchr("+-", *i)) {

                    temp = GetTop(Sptr);

                    if (strchr("*/", temp)) {
                        buf[j++] = temp;
                        pop(Sptr);
                        Push(Sptr, *i);
                    } else if (temp == '(') {
                        Push(Sptr, *i);
                    } else {
                        Push(Sptr, *i);
                    }

                } else if (*i == '(') {
                    Push(Sptr, *i);
                } else if (*i == ')') {
                    while (!isEmpty(Sptr)) {
                        if (GetTop(Sptr) != '(')
                            buf[j++] = pop(Sptr);
                        else {
                            pop(Sptr);
                            break;
                        }
                    }
                } else if (strchr("*/", *i)) {
                    Push(Sptr, *i);
                }
        }
        if (!*i)
            break;
        i++;
    }

    if (*i == 0) {
        while (!isEmpty(Sptr)) {
            buf[j++] = pop(Sptr);
        }
    }

    buf[j] = 0;
    j = 0;
    while (buf[j]) {
        *(s + j) = buf[j];
        j++;
    }
    *(s + j) = 0;
    free(Sptr);
}

void EvaluateInfix(char *s) {
    Stack *Spnd = (Stack *) malloc(sizeof(Stack));
    InitStack(Spnd, 20);
    char buf[80];
    int i, k;

    while (*s) {
        switch (*s) {
            case '+':
                k = pop(Spnd) + pop(Spnd);
                Push(Spnd, k);
                break;
            case '-':
                k=pop(Spnd);
                k=pop(Spnd)-k;
                Push(Spnd, k);
                break;
            case '*':
                k = pop(Spnd) * pop(Spnd);
                Push(Spnd, k);
                break;
            case '/':
//                此处注意不要引发歧义。
                k=pop(Spnd);
                k=pop(Spnd)/k;
                Push(Spnd, k);
                break;
            default:
                Push(Spnd, (int) *s - 48);

        }
        s++;
    }
    printf("The value is %d.\n", pop(Spnd));
}

