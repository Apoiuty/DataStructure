//
// Created by Apoiuty on 2019/9/25.
//

#ifndef DATA_STRUCTURE_WANGDAO2_H
#define DATA_STRUCTURE_WANGDAO2_H

#include "linkedlist.h"
#include "dNode.h"

typedef struct fNode {
    struct fNode *pre;
    struct fNode *next;
    int fre;
    int data;
} FNode;

void Delte_x(Node *head, int x, Node *pre);
//删除不含头结点的单链表L中x的递归算法

//删除含头结点的单链表L中x的递归算法
void WithHead_Delte_x(Node *head, int x, Node *pre);

//反向输出各节点的值
void Inverse_Output(Node *head);

//删除链表中的最小元素
void Delete_Min(Node *head);

//带头结点的就地转置
void Inverse_Withhead(Node *head);

//插入递增排序
void Sort_WithHead(Node *head);

//删除介于m和M之间的值
void Delete_mM(Node *head, int m, int M);

//寻找单链表公共节点
Node *Find_Common_Node(Node *head1, Node *head2);

//链表长度
int Length_WithHead(Node *head);

//输出递增顺序的链表并释放存储空间
void Min_Delete(Node *head);

//将一个链表L分为两个链表a和b, a为奇数元素, b中为偶数元素
void DisCreat_1(Node *L, Node **a, Node **b);

//将一个链表L分为两个链表a和b, a为奇数元素, b中为偶数元素
void DisCreat_2(Node *L, Node **a, Node **b);

//删除有序表中相同的元素
void Delete_Same(Node *head);

//合并递增双链表和递减单链表
Node *MergeList(Node *a, Node *b);

//产生a, b两链表公共元素链表C
Node *Get_Common(Node *a, Node *b);

//b链表是否是a链表的连续子序列
int Pattern(Node *a, Node *b);

//判断双循环链表是否对称
int Symmety(DNode *head);

//将b链表接到a链表之后, a b均为循环单链表
void Link(Node *a, Node *b);

//返回元素为x的双向链表的位置
FNode * Locate(FNode *head, int x);

//寻找倒数第k位置的链表元素
int Find_k(Node *head, int k);

#endif //DATA_STRUCTURE_WANGDAO2_H

