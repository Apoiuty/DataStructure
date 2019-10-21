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
    int mark;
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

typedef struct aov {
    int *cnt;
//    各顶点的入度
    Vertex *vertexlist;
    int n;
//    边的数量和顶点的数量
    int n_vertex;
    int n_edge;
} AOV;

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

/**
 * 拓扑排序
 * @param aov aov网
 */
void TopSort(AOV *aov);

/**
 * 图的广度遍历算法
 * @param g 图结构
 */
void BFS(Graph *g);

/**
 * 从相邻矩阵生成邻接表
 * @param n 节点个数
 * @param adj 相邻矩阵
 * @return 返回邻接表表示的图
 */
Graph *Adj2Grapg(int n, int adj[][n]);


/**
 * 用DFS判断图中是否存在回路
 * @param g 图
 * @return 逻辑值
 */
int HaveLoop(Graph *g);

/**
 * DFS对图进行拓扑排序
 * @param g 图
 */
void dfsTopSort(Graph *g);

/**
 * DFS对图进行拓扑排序
 * @param g
 * @param i
 * @param visited
 * @param time
 * @param t
 */
void dfs_top_sort(Graph *g, int i, int visited[], int time[], int *t);

#endif //DATA_STRUCTURE_GRAPH_H
