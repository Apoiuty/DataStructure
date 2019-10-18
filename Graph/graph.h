//
// Created by Apoiuty on 2019/10/17.
//

#ifndef DATA_STRUCTURE_GRAPH_H
#define DATA_STRUCTURE_GRAPH_H


//边表数据结构
struct edge {
    int jj;
    int weight;
    struct edge *next;
};

typedef struct edge Edge;

//连通图的边
struct Edge {
    int vi, vj;
    int weight;
};

typedef struct Edge edge;

//顶点的数据类型
typedef struct vertex {
    int data;
    Edge *out;
} Vertex;

//图的数据结构
struct graph {
    Vertex *items;
    int num;
    int maxN, maxEdge;
    int nEdge;
};

typedef struct graph Graph;

/**
 * 返回定点i的数据信息
 * @param g 图
 * @param i 第i个节点
 * @return 数据信息
 */
int ReturnValue(Graph *g, int i);

/**
 * 对图进行深度遍历
 * @param g 图指针
 */
void DFS(Graph *g);

/**
 * 图深度遍历算法
 * @param g 根节点
 * @param i 节点序号
 * @param visited 已遍历数组
 */
void dfs(Graph *g, int i, int visited[]);

/**
 * 获取下一个与i相连的顶点编号
 * @param pGraph 图
 * @param i 当前节点
 * @param next 下一个节点
 * @return 下一个未遍历节点的编号
 */
int ReturnNextValue(Graph *pGraph, int i, int next);

/**
 * Prim算法生成最小生成树
 * @param T 记录最小生成树
 * @param n 结点个数
 * @param adj 连接矩阵
 */
void prim(edge T[], int n, int *adj);

//length表示路径权重, pre表示路径的前一个节点
typedef struct {
    int length;
    int pre;
} path;

/**
 * 起始点为k的单源最短路径
 * @param k 起始点
 */
void DIJ(int k, int n, int adj[][n], path dist[]);

/**
 * 佛洛依德算法
 * @param n 节点个数
 * @param D 记录两点间的最短路径
 * @param path path_i_j记录从i到j的中间节点
 * @param adj 邻接矩阵
 */
void Floyd(int n, int D[][n], int path[][n], int adj[][n]);

#endif //DATA_STRUCTURE_GRAPH_H
