//
// Created by Apoiuty on 2019/9/26.
//

#include "String.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

//初始化函数
void Init_String(string *S, char *s) {
    char *p1, *p2;
    for (p1 = S->str, p2 = s; *p2; S->len++) {
        *(p1++) = *(p2++);
    }
    *p1 = 0;
}

//将字符串S附加到本字符串之后
void Concatenate(string *pre, string *after) {
    if (pre->len + after->len > MAX_LEN) {
        printf("String length overflow!\n");
    } else {
        memcpy(pre->str + pre->len, after->str, after->len + 1);
        pre->len += after->len;
    }
}

//将字符串插入到pos所指的位置
void InsertS(string *pre, int pos, string *after) {
    if (pre->len + pos + after->len > MAX_LEN) {
        printf("String length overflow!\n");
    } else {
        memcpy(pre->str + pos + after->len, pre->str + pos, pre->len - pos + 1);
//        移动出after.len个位置
        memcpy(pre->str + pos, after->str, after->len);
//        复制元素
        pre->len += after->len;
    }
}

//删除pos起连续len个字符
void DeleteS(string *s, int pos, int len) {
    if (pos + len > s->len) {
        len = s->len - pos;
    }
//    如果删除的数目大于长度

    s->len -= len;
    memcpy(s->str + pos, s->str + pos + len, s->len - pos + 1);
//    多移动一个空字符
}

//提取本字符串
char *Getstring(string *s) {
    char *temp = (char *) malloc(sizeof(s->len + 1));
    memcpy(temp, s->str, s->len + 1);
    return temp;
}

//提取从pos起len个字符
string *GetS(string *s, int pos, int len) {
    if (pos + len > s->len) {
        len = s->len - pos;
    }
//    如果读取的数目大于长度

    string *temp = (string *) malloc(sizeof(string));

    Init_String(temp, "");

    memcpy(temp->str, s->str + pos, len);
    temp->len = len;
    temp->str[len] = 0;
    return temp;
}

//返回KMP算法的next数组
int *GetNext(char *p) {
    int i = 0, j = -1;
    int len = (int) strlen(p);
    int *next = (int *) malloc(len * sizeof(int));
    next[0] = -1;

//    0位不匹配进行其他操作
    while (i < len) {
        if (j == -1 || p[i] == p[j]) {
            i++;
            j++;
            next[i] = j;
//            j时匹配的个数, 不匹配时应使用的指针地址
        } else
            j = next[j];
//        如果不匹配如何回溯
    }

    return next;
}

//从本字符串中查找p出现的位置
int KMP(string *s, char *p) {
    int len = (int) strlen(p);
    int *next = GetNext(p);
    int i, j;
    for (i = 0, j = 0; i < s->len && j < len;) {
        if (s->str[i] == p[j]) {
            i++, j++;
        } else {
            if (next[j] >= 0) {
                j = next[j];
            } else {
                j = 0, i++;
            }
        }
    }

    if (j >= len) {
//        if found
        return i - len;
    } else {
//        not found
        return -1;
    }
}

//BM算法求bad char数组, 数组中为应移动到的位置
void PreBmBc(char *p, int *bad_char) {
//    bad_char由调用者分配
    memset(bad_char, -1, sizeof(int) * CHAR_MAX);
//    把所有字符的位置置0
    int len = (int) strlen(p);
//    发现坏字符应移动的位置
    for (int i = 0; i < len; ++i) {
        bad_char[p[i]] = i;
    }
}

//求好后缀数组长度
void suffix(char *p, int suff[]) {
//    https://blog.csdn.net/chenhanzhun/article/details/39938989

    int i, j, len = strlen(p);
    suff[len - 1] = len;

    for (i = len - 2; i >= 0; i--) {
        j = i;
        while (j >= 0 && p[j] == p[len - 1 - (i - j)])
            j--;

        suff[i] = i - j;
    }

}


//求好后缀移动的距离
void PreBmGs(char *p, int bmGs[]) {
    int i, j;
    int len = strlen(p);
    int suff[len];

//    计算好后缀数组长度
    suffix(p, suff);

    memset(bmGs, -1, len * sizeof(int));

//    模式中存在好后缀部分匹配, 则部分匹配一定为前缀; 要围绕好前缀来思考
    j = 0;
    for (i = len - 1; i >= 0; i--) {
        if (suff[i] == i + 1) {
            for (; j < len - 1 - i; j++)
                if (bmGs[j] == -1)
                    bmGs[j] = i;
        }
    }

//    模式串中存在匹配
    for (i = 0; i <= len - 2; i++) {
        j = len - 1 - suff[i];
        bmGs[j] = i;
    }
}


//BM算法
int BM(char *s, char *pattern) {
    if (strlen(s) < strlen(pattern))
        return -1;

    int BadCharTable[CHAR_MAX];

//    获取坏字符转移表
    PreBmBc(pattern, BadCharTable);

//    获取后缀表和好后缀转移表
    int suff[strlen(pattern)];
    int bmGs[strlen(pattern)];

//    后缀表
    suffix(pattern, suff);
//    好后缀转移表
    PreBmGs(pattern, bmGs);


    int len_p = (int) strlen(pattern);
//    cur指向被查找字符串
    int cur = len_p - 1;
//    p_cur指向pattern
    int p_cur = len_p - 1;

    int rear, shift;
    while (s[cur]) {
        rear = cur;
        while (s[cur] == pattern[p_cur] && p_cur >= 0)
            cur--, p_cur--;
//        查找到匹配结果
        if (p_cur < 0)
            return cur + 1;

//        没有查找到, 判断下一次移动位置
        p_cur = BadCharTable[s[cur]] < bmGs[p_cur] ? BadCharTable[s[cur]] : bmGs[p_cur];
        shift = (int) strlen(pattern) - 1 - p_cur;

//        超出边界退出
        if (cur + shift > strlen(s))
            return -1;

//        下一个迭代位置
        cur = rear + shift;
        p_cur = len_p - 1;
    }
//    没有查找到
    return -1;
}