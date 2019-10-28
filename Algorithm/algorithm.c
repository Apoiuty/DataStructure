//
// Created by Apoiuty on 2019/10/28.
//

#include <stdbool.h>
#include "algorithm.h"

int IntegerDivision(int n, int m) {
    if (m == 1) {
        return 1;
    } else if (n < m) {
        return IntegerDivision(n, n);
    } else if (n == m) {
        return 1 + IntegerDivision(n, n - 1);
    } else if (n > m && m > 1) {
        return IntegerDivision(n, m - 1) + IntegerDivision(n - m, m);
    }
}

int MazeTravel(int (*maze)[10], int n, int m, Pos *path) {
    int top, i, j, k, h, dir;
    int increase[8][2] = {{0,  1},
                          {1,  1},
                          {-1, 1},
                          {0,  -1},
                          {1,  0},
                          {1,  -1},
                          {-1, -1},
                          {-1, 0}};
    top = 0;
    i = j = 1;
    dir = 0;
    path[top].col = j;
    path[top].row = i;
    path[top].dir = dir;

    maze[i][j] = -1;

    while (top >= 0 || dir < 8) {
        if (dir < 8) {
            k = i + path[top].row;
            h = j + path[top].col;

            if (maze[k][h] != 0 && maze[k][h] != -1) {
                maze[k][h] = -1;
                top++;
                path[top].row = k;
                path[top].col = h;
                path[top].dir = dir;

                i = k;
                j = h;
                dir = 0;
                if (i == m - 2 && k == m - 2) {
                    return top;
                } else
                    dir++;

            } else {
                dir = path[top].dir++;
                top--;
                if (top >= 0) {
                    i = path[top].row;
                    j = path[top].col;
                }
            }
        }
    }

    return 0;
}

bool place(int k, int n, int pInt[]) {
    for (int i = 1; i < k; i++) {
        if (abs(k - i) == abs(pInt[k] - pInt[i]) || pInt[i] == pInt[k]) {
            return 0;
        }
    }
    return 1;
}

int EightQueen(int n) {
    int k;
//   k为第k个皇后
    int x[n];
    memset(x, 0, sizeof(x));

    k = 1;
    int sum = 0;
    x[k] = 0;

    while (k) {
        x[k] += 1;
        while (x[k] <= n && !(place(k, n, x)))
            x[k]++;

        if (x[k] <= n) {
            if (k == n) {
                sum++;
                for (int i = 1; i <= n; ++i) {
                    for (int j = 1; j < x[i]; ++j) {
                        printf(" ");
                    }
                    printf("*\n");
                }

                printf("--------\n");
            } else {
                k++;
                x[k] = 0;
            }
        } else
            k--;
    }

    return sum;
}

Seq *CreatEmptyQueue(void) {
    Seq *q;
    q = (Seq *) malloc(sizeof(Seq));
    if (q) {
        return q;
    }
}

int isEmptyQueue(Seq *seq) {
    return seq->front == seq->rear;
}

void enQueue(Seq *q, DataType x) {
    if ((q->rear + 1) % 100 == q->front) {
        exit(1);
    } else {
        q->queue[q->rear] = x;
        q->rear = (q->rear + 1) % 100;
    }
}

void deQueue(Seq *q) {
    if (q->rear != q->front) {
        q->front = (q->front + 1) % 100;
    }
}

DataType frontQuueue(Seq *seq) {
    DataType result;
    result = seq->queue[seq->front];
    return result;
}

void QueueSort(int n, double *p, double *w) {
    double a, b, temp;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i; j < n - 1; ++j) {
            a = p[j] / w[j];
            b = p[j + 1] / w[j + 1];
            if (a < b) {
                temp = p[j + 1];
                p[j + 1] = p[j];
                p[j] = temp;

                temp = w[j + 1];
                w[j + 1] = w[j];
                w[j] = temp;

            }
        }
    }
}

double up(int k, double c, int n, double *p, double *w) {

}




