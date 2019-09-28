//
// Created by Apoiuty on 2019/9/26.
//

#ifndef DATA_STRUCTURE_STRING_H
#define DATA_STRUCTURE_STRING_H
//串的数据结构
#define MAX_LEN 1024

struct Mystring {
    int len;
    char str[MAX_LEN + 1];
};

typedef struct Mystring string;

//初始化函数
void Init_String(string *S, char *s);

//将字符串S附加到本字符串之后
void Concatenate(string *pre, string *after);

//将字符串插入到pos所指的位置
void InsertS(string *pre, int pos, string *after);

//删除pos起连续len个字符
void DeleteS(string *s, int pos, int len);

//提取从pos起len个字符
string *GetS(string *s, int pos, int len);

//提取本字符串
char *Getstring(string *s);

//从本字符串中查找p出现的位置
int KMP(string *s, char *p);

//返回KMP算法的next数组
int *GetNext(char *p);

//BM算法求bad char数组
void PreBmBc(char *p, int *bad_char);

//求好后缀数组长度
void suffix(char *p,int suff[]);

//求好后缀移动的距离
void PreBmGs(char *p,int bmGs[]);

//BM算法
int BM(char *s, char *pattern);
#endif //DATA_STRUCTURE_STRING_H
