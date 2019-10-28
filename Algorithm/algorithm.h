//
// Created by Apoiuty on 2019/10/28.
//

#ifndef DATA_STRUCTURE_ALGORITHM_H
#define DATA_STRUCTURE_ALGORITHM_H

#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct {
    int step;
    int price;
    int weight;
    double max, min;
    unsigned long ChooseMark;
} DataType;

struct SeqQueue {
    int front, rear;
    DataType queue[100];
};

typedef struct SeqQueue Seq;

/**
 * 整数划分
 * @param n 正整数n
 * @param m 最大加数为m
 * @return 划分个数
 */
int IntegerDivision(int n, int m);

/**
 * 行号, 列号和方向号
 */
typedef struct {
    int row, col, dir;
} Pos;

/**
 * 迷宫问题
 * @param maze 迷宫的数组表示, 0表示通路, 1表示不通
 * @param n 行数
 * @param m 列数
 * @param path 路径数组
 * @return 路径数组的大小
 */
int MazeTravel(int maze[][10], int n, int m, Pos path[]);

/**
 * n皇后问题
 * @param n 皇后数目
 * @return 问题的解决方法个数
 */
int EightQueen(int n);

/**
 * 构建空的顺序队列
 * @return 顺序队列指针
 */
Seq *CreatEmptyQueue(void);

/**
 * 判断seq是否为空
 * @param seq
 * @return
 */
int isEmptyQueue(Seq *seq);

/**
 * 在队列中插入一个元素
 * @param q
 * @param x
 */
void enQueue(Seq *q, DataType x);

/**
 * 删除队头元素
 */
void deQueue(Seq *q);

/**
 * 求队头元素
 * @param seq
 * @return
 */
DataType frontQuueue(Seq *seq);

/**
 * 物品按性价比重新排序
 * @param n 物品个数
 * @param p 物品价格
 * @param w 物品质量
 */
void QueueSort(int n, double p[], double w[]);

/**
 * 求可能打的最大值
 * @param k
 * @param c
 * @param n
 * @param p
 * @param w
 * @return
 */
double up(int k, double c, int n, double p[], double w[]);

#endif //DATA_STRUCTURE_ALGORITHM_H
