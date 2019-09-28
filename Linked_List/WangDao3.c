//
// Created by Apoiuty on 2019/9/28.
//

#include "WangDao3.h"
#include "dNode.h"

//括号匹配检查
int BracketCHeck(char str[]) {
    char Bracket_Stack[50];
    int i = -1;
//    i为栈指针, 指向Top元素

    for (int j = 0; str[j]; ++j) {
        switch (str[j]) {
            case '(':
                Bracket_Stack[++i] = '(';
                break;
            case ')':
                if (Bracket_Stack[i] != '(')
                    return 0;
                else
                    i--;
                break;

            case '[':
                Bracket_Stack[++i] = '[';
                break;
            case ']':
                if (Bracket_Stack[i] != '[')
                    return 0;
                else
                    i--;
                break;

            case '{':
                Bracket_Stack[++i] = '{';
                break;
            case '}':
                if (Bracket_Stack[i] != '{')
                    return 0;
                else
                    i--;
                break;
            default:;

        }
    }

    if (i != -1) {
        return 0;
    } else
        return 1;
}

//求Pn(x)
int Pn(int x, int n) {
    int Pn_2 = 1, Pn_1 = 2 * x;
    if (n == 0)
        return 1;
    if (n == 1)
        return 2 * x;


    int Pn;
    for (int i = 2; i <= n; ++i) {
        Pn = 2 * x * Pn_1 - 2 * (i - 1) * Pn_2;
        Pn_2 = Pn_1;
        Pn_1 = Pn;
    }

    return Pn;
}

//Pn迭代版
int pn(int x,int n){
    if(n==0)
        return 1;
    else if(n==1)
        return 2*x;
    else
        return 2 * x * pn(x, n - 1) - 2 * (n - 1) * pn(x, n - 2);
}