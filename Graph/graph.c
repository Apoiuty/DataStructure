//
// Created by Apoiuty on 2019/10/17.
//

#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int ReturnNextValue(Graph *pGraph, int i, int next);

/**
 * 返回定点i的数据信息
 * @param g 图
 * @param i 第i个节点
 * @return 数据信息
 */
int ReturnValue(Graph *g, int i) {
    if (i >= 0 && i < g->maxN) {
        Edge *p = g->items[i].out;
        if (p) {
            return p->jj;
        }
    } else {
        return -1;
    }

}


/**
 * 对图进行深度遍历
 * @param g 图指针
 */
void DFS(Graph *g) {
    int visited[g->maxN];
    memset(visited, 0, sizeof(visited) * sizeof(int));

    for (int i = 0; i < g->num; ++i) {
        if (!visited[i]) {
            dfs(g, i, visited);
        }
    }
}

/**
 * 图深度遍历算法
 * @param g 根节点
 * @param i 节点序号
 * @param visited 已遍历数组
 */
void dfs(Graph *g, int i, int visited[]) {
    int next;
    visited[i] = 1;

    next = ReturnValue(g, i);
    while (next != -1) {
        if (!visited[next]) {
            dfs(g, next, visited);
        } else {
            next = ReturnNextValue(g, i, next);
        }
    }
}

int ReturnNextValue(Graph *pGraph, int i, int next) {
    Edge *p;
    if (i != -1) {
        p = pGraph->items[i].out;
        while (p) {
            if (p->jj == next && p->next)
                return p->next->jj;

            p = p->next;

        }
    }

    return -1;
}

/**
 * Prim算法生成最小生成树
 * @param T 记录最小生成树
 * @param n 结点个数
 * @param adj 连接矩阵
 */
void prim(edge T[], int n, int *adj) {
//    初始化最小生成树, 从1-2,1-3到1-n
    for (int i = 1; i < n; ++i) {
        T[i - 1].vi = 1;
        T[i - 1].vj = i + 1;
        T[i - 1].weight = *(adj + i);
    }

    int min, weight, k, index, vj;
    edge temp;
    for (int j = 0; j < n - 1; ++j) {
        min = 32767;
        index = j;

//        从U中查找到W最小的路径长度并交换
        for (k = j; k < n - 1; ++k) {
            if (T[k].weight < min) {
                min = T[k].weight;
                index = k;
            }
        }

        temp = T[index];
        T[index] = T[j];
        T[j] = temp;
        vj = T[j].vj;
//        更新从U到W的权重
        for (int i = j + 1; i < n - 1; ++i) {
            weight = *(adj + (vj - 1) * n + (T[i].vj - 1));
            if (weight < T[i].weight) {
                T[i].weight = weight;
                T[i].vi = vj;
            }
        }
    }

}

/**
 * 起始点为k的单源最短路径
 * @param k 起始点
 * @param n 节点个数
 * @param adj 相邻矩阵中aij表示权vi--vj
 * @param dist 路径节点路径长度和前驱节点
 */
void DIJ(int k, int n, int adj[][n], path dist[]) {
//    初始化dist数组
//    dist[i]为k--i的路径长度
    for (int i = 0; i < n; ++i) {
        dist[i].length = adj[k][i];
        if (dist[i].length < INT_MAX)
            dist[i].pre = k;
        else
            dist[i].pre = -1;
    }
//    k节点已进入A组
    adj[k][k] = 1;

    int min, i_min;
    for (;;) {
        min = INT_MAX;
        i_min = -1;
        for (int i = 0; i < n; ++i) {
//            如果节点i没有进入路径且其在B组中权值最小
            if (adj[i][i] == 0 && dist[i].length < min) {
                min = dist[i].length;
                i_min = i;
            }
        }

//        如果所有节点都进入了路径或者没有路径从A到B
        if (i_min == -1)
            return;

//        修改B中节点的权值
        adj[i_min][i_min] = 1;
        for (int j = 0; j < n; ++j) {
            if (adj[j][j] == 0 && dist[j].length > dist[i_min].length + adj[i_min][j]) {
                dist[j].length = dist[i_min].length + adj[i_min][j];
                dist[j].pre = i_min;
            }
        }

    }


}

/**
 * 佛洛依德算法
 * @param n 节点个数
 * @param D 记录两点间的最短路径
 * @param path path_i_j记录从i到j的中间节点
 * @param adj 邻接矩阵
 */
void Floyd(int n, int D[][n], int path[][n], int adj[][n]) {
    int max = 32767, i, j, k;
//    D数组和path数组初始化
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
//            如果i和j节点有路径
            if (adj[i][j] != max) {
//                i到j的中间节点为i+1
                path[i][j] = i + 1;
//                i到j的路径权重为adj_i_j
            } else
                path[i][j] = 0;
            D[i][j] = adj[i][j];
        }
    }


    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
//                如果i到j可通过中间节点k减小权重,则把k设为中间节点
                if (D[i][j] > D[i][k] + D[k][j]) {
                    D[i][j] = D[i][k] + D[k][j];
                    path[i][j] = path[k][j];
                }
            }
        }

    }
}

/**
 * 拓扑排序
 * @param aov aov网
 */
void TopSort(AOV *aov) {
    int addcnt = 0;
    int Toporder[15];
    int top = -1, i, j;

    for (i = 0; i < aov->n; i++) {
        if (aov->cnt[i] == 0) {
            aov->cnt[i] = top;
            top = i;
        }
    }

    Edge *p;
    for (i = 0; i < aov->n; i++) {
        if (top == -1) {
            exit(1);
        } else {
            addcnt++;
            j = top;
            top = aov->cnt[top];
            Toporder[i] = j + 1;
            p = aov->vertexlist[j].out;
            while (p) {
                int k = p->jj;
                if (--aov->cnt[k] == 0) {
                    aov->cnt[top] = top;
                    top = k;
                }
                p = p->next;

            }

        }
    }
}
