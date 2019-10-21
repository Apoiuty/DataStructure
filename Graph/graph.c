//
// Created by Apoiuty on 2019/10/17.
//

#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int ReturnNextValue(Graph *pGraph, int i, int next);

int haveloop(Graph *g, int i, int visited[], int circle[]);

/**
 * 返回定点i的数据信息
 * @param g 图
 * @param i 第i个节点
 * @return 数据信息
 */
int ReturnValue(Graph *g, int i) {
    if (i >= 0 && i < g->num) {
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
    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < g->num; ++i) {
        if (!visited[i]) {

            dfs(g, i, visited);
        }
    }
    printf("\n");
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

    printf("%d ", g->items[i].data);
    next = ReturnValue(g, i);
    while (next != -1) {
        if (!visited[next - 1]) {
            dfs(g, next - 1, visited);
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

/**
 * 图的广度遍历算法
 * @param g 图结构
 */
void BFS(Graph *g) {
//    queue用来保存未访问的节点
    Vertex queue[g->maxN];
    int q_index = 0, q_top = 1;
    int visited[g->num];
    memset(visited, 0, sizeof(visited));

    int next;
    for (int i = 0; i < g->num;) {
        if (!visited[i]) {
//            将未访问节点入队
            printf("%d ", g->items[i].data);
            visited[i] = 1;
            queue[q_index++] = g->items[i];
//            将未访问节点的子节点入队
        }
        next = ReturnValue(g, i);
        while (next != -1) {
            next--;
            if (!visited[next]) {
                visited[next] = 1;
                printf("%d ", g->items[next].data);
                queue[q_index++] = g->items[next];
            }
            next = ReturnNextValue(g, i, next + 1);
        }

//        如果队列中还有元素, 则遍历队列
        if (q_top < q_index)
            i = queue[q_top++].data - 1;
        else {
            printf("|");
            i = 0;
            while (visited[i] == 1 && i < g->num)
                i++;
        }
    }

    printf("\n");

//    int i;
//    cur = g->items;
//    while (cur) {
//
//        i = cur - g->items;
//        if (visited[i] == 0) {
//            visited[i] = 1;
//            queue[q_index++] = *cur;
//
////            遍历其孩子节点
//            next = cur->out;
//            while (next) {
//                i = next->jj;
//                if (visited[i] == 0) {
//                    visited[i] = 1;
//                    queue[q_index++] = g->items[i];
//                }
//                next = next->next;
//            }
//        }
//
////        检查是否遍历完了
//        if (q_top >= g->num)
//            break;
//
//        if (q_top < q_index) {
////            如果队列中有元素未遍历
//            cur = &(queue[++q_top]);
//        } else {
//            i = 0;
//            while (visited[i] == 1 && i < g->num)
//                i++;
//
////            寻找未遍历节点
//            if (i < g->num)
//                cur = g->items + i;
//            else
//                break;
//        }
//    }
}


/**
 * 从相邻矩阵生成邻接表
 * @param n 节点个数
 * @param adj 相邻矩阵
 * @return 返回邻接表表示的图
 */
Graph *Adj2Grapg(int n, int adj[][n]) {
    Graph *g;
    g = (Graph *) malloc(sizeof(Graph));
    g->num = g->maxN = n;
    g->nEdge = 0;
    g->maxEdge = n * (n - 1);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (adj[i][j] > 0 && adj[i][j] < INT_MAX)
                g->nEdge++;
        }
    }

    Edge *new;
    g->items = (Vertex *) malloc(sizeof(Vertex) * n);
    for (int k = 0; k < n; ++k) {
        g->items[k].data = k + 1;
        g->items[k].out = NULL;
        for (int i = 0; i < n; ++i) {
            if (adj[k][i] > 0 && adj[k][i] < INT_MAX / 2) {
                new = (Edge *) malloc(sizeof(Edge));
                new->weight = adj[k][i];
                new->jj = i + 1;
                new->next = g->items[k].out;
                g->items[k].out = new;
            }
        }
    }

    return g;

}

/**
 * 用DFS判断图中是否存在回路
 * @param g 图
 * @return 逻辑值
 */
int HaveLoop(Graph *g) {
    int visited[g->maxN];
    int circle[g->maxN];
    memset(visited, 0, sizeof(visited));
    int flag = 0;

    for (int i = 0; i < g->num; ++i) {
        memset(circle, 0, sizeof(circle));
        if (!visited[i]) {
            circle[i] = 1;
            flag = haveloop(g, i, visited, circle);
        }
        if (flag)
            return 1;
    }
    return 0;
}

int haveloop(Graph *g, int i, int visited[], int circle[]) {
    int Circle[g->maxN];
    memcpy(Circle, circle, (int) sizeof(g->maxN) * sizeof(int));

    int next, flag = 0;
    next = ReturnValue(g, i);
    while (next != -1) {
        next--;
        if (!visited[next]) {
            visited[next] = 1;
            Circle[next] = 1;
            flag = haveloop(g, next, visited, Circle);
            if (flag)
                return 1;
        } else if (Circle[next] == 1) {
            return 1;
        }

        next = ReturnNextValue(g, i, next + 1);
        memcpy(Circle, circle, (int) sizeof(g->maxN) * sizeof(int));

    }

    return 0;

}


/**
 * DFS对图进行拓扑排序
 * @param g 图
 */
void dfsTopSort(Graph *g) {
    int visited[g->num];
    int time[g->num];
    int t = 0;

    memset(visited, 0, sizeof(visited));
    memset(time, 0, sizeof(time));

    for (int i = 0; i < g->num; ++i) {
        if (!visited[i]) {
            dfs_top_sort(g, i, visited, time, &t);
            time[i] = t;
        }
    }

    int max = 0, index;
    for (int j = 0; j < g->num; ++j) {
        max = 0;
        for (int i = 0; i < g->num; ++i) {
            if (time[i] > max) {
                max = time[i];
                index = i;
            }
        }

        time[index] = 0;
        printf("%d ", index + 1);
    }
    printf("\n");
}

/**
 * DFS对图进行拓扑排序
 * @param g
 * @param i
 * @param visited
 * @param time
 * @param t
 */
void dfs_top_sort(Graph *g, int i, int visited[], int time[], int *t) {
    visited[i] = 1;

    int next;

    next = ReturnValue(g, i);
    while (next != -1) {
        next--;
        if (!visited[next]) {
            dfs_top_sort(g, next, visited, time, t);
            time[next] = ++(*t);
        }

        next = ReturnNextValue(g, i, next + 1);
    }
}