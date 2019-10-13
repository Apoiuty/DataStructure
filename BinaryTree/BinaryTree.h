//
// Created by Apoiuty on 2019/10/6.
//

#ifndef DATA_STRUCTURE_BINARYTREE_H
#define DATA_STRUCTURE_BINARYTREE_H


#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//二叉树的左右节点链式存储结构
struct binarytreenode {
    struct binarytreenode *left, *right, *parent;
    int data;
};

typedef struct binarytreenode BinaryTreeNode;

//二叉树结构
struct binarytree {
    BinaryTreeNode *root;
};

typedef struct binarytree BinaryTree;

//线索化二叉树
typedef struct threaded_tree {
    int ltag, rtag;
    int data;
    struct threaded_tree *left, *right;
} ThreadedTree;

//表达式二叉树结构
typedef struct expr {
    char expr;
    struct expr *left, *right;
} Expr;

/**
 * 二叉树节点初始化函数
 * @param btree 要初始化的节点
 * @param left 左子节点
 * @param right 右子节点
 * @param data 数据项
 */
void InitBinaryTreeNode(BinaryTreeNode *btree, BinaryTreeNode *left, BinaryTreeNode *right, int data);

/**
 * 创建二叉树节点
 * @param left 左子节点
 * @param right 右子节点
 * @param data 数据
 * @return 创建好的节点
 */
BinaryTreeNode *CreatBinaryTreeNode(BinaryTreeNode *left, BinaryTreeNode *right, int data);

/**
 * 初始化二叉树结构
 * @param bt 要初始化的树
 */
void InitBinaryTree(BinaryTree *bt);

/**
 * 判断二叉树是否为空
 * @param bt 二叉树
 * @return 逻辑值
 */
int IsEmptyTree(BinaryTree *bt);

/**
 * 返回二叉树根节点的值
 * @param bt
 * @return 根节点值
 */
int GetRoot(BinaryTree *bt);

/**
 * 构造二叉树
 * @param bt 二叉树根节点
 * @param left 左子节点
 * @param right 右子节点
 * @return 构造的二叉树
 */
BinaryTreeNode *MakeTree(BinaryTree *bt, BinaryTreeNode *left, BinaryTreeNode *right, int data);

/**
 * 前序遍历二叉树
 * @param root 根节点
 */
void PreOrder(BinaryTreeNode *root);

/**
 * 后序遍历二叉树
 * @param root 根节点
 */
void PostOrder(BinaryTreeNode *root);

/**
 * 中序遍历二叉树
 * @param root 根节点
 */
void InOrder(BinaryTreeNode *root);

/**
 * 前序遍历二叉树(非递归)
 * @param root 根节点
 */
void NLR(BinaryTreeNode *root);

/**
 * 对称序遍历二叉树
 * @param root 根节点
 */
void LNR(BinaryTreeNode *root);

/**
 * 后序遍历二叉树
 * @param root 根节点
 */
void LRN(BinaryTreeNode *root);

/**
 * 线索化二叉树的中序遍历算法
 * @param root
 * @param pre
 */
void InorderThreaded(ThreadedTree *root, ThreadedTree **pre);

/**
 * 返回指定节点的对称后继节点值
 * @param p 指定节点
 * @return 后继节点的data
 */
int Inordernext(ThreadedTree *p);

/**
 * 对称序列遍历线索化二叉树
 * @param root 根节点
 */
void ThreadedInTravel(ThreadedTree *root);


/**
 * 在对称序列化二叉树节点p后插入insert
 * @param p
 * @param insert
 */
void InsertThreadedTree(ThreadedTree *p, ThreadedTree *insert);

/**
 * 后序遍历算法
 * 使用一个前序指针指示是否访问了右节点, 从而判断是否输出根节点
 * @param root 根节点
 */
void PostOrder2(BinaryTreeNode *root);


/**
 * 创建n个节点的完全二叉树
 * @param n 节点数目
 * @return 根节点
 */
BinaryTreeNode *CreatBinaryTreeN(int n);


/**
 * 逆序层次遍历二叉树
 * @param root 根节点
 */
void Inverse_LevelOrder(BinaryTreeNode *root);


/**
 * 获取二叉树深度
 * @param root 根节点
 * @return 树深度
 */
int GetTreeHeight(BinaryTreeNode *root);

/**
 * 从前序和中序遍历生成二叉树
 * @param A 前序
 * @param B 中序
 * @param l1 前序下标
 * @param h1 前序上标
 * @param l2 中序下标
 * @param h2 中序下标
 * @return 二叉树根节点
 */
BinaryTreeNode *GetTreeFromPreAndIn(int A[], int B[], int l1, int h1, int l2, int h2);

/**
 * 判断是否为完全二叉树
 * @param root 根节点
 * @return 逻辑值
 */
int IsCompleteBTree(BinaryTreeNode *root);

/**
 * 返回二叉树的双分支节点数
 * @param root 根节点
 * @return 双分支节点数
 */
int N_2Branch(BinaryTreeNode *root);

/**
 * 交换左右子树
 * @param root 根节点
 */
void ExchangeLeftRight(BinaryTreeNode *root);

/**
 * 访问二叉树中序遍历第K个值
 * @param root 根节点
 */
void InOrderK(BinaryTreeNode *root, int k);

/**
 * 删除值为x的根子树
 * @param root 根节点
 * @param x 要删除的值
 */
void Delete_x(BinaryTreeNode *root, int x);

/**
 * 打印值为x节点的父节点
 * @param root 根节点
 * @param x 值x
 */
int Print_x(BinaryTreeNode *root, int x);


/**
 * 查找p,q节点的最近公共父节点
 * @param root 二叉树根节点
 * @param p
 * @param q
 */
void Ancestor(BinaryTreeNode *root, BinaryTreeNode *p, BinaryTreeNode *q);

/**
 * 求取二叉树的宽度
 * @param root 根节点
 * @return 宽度
 */
int Get_TreeWidth(BinaryTreeNode *root);

/**
 * 前序满二叉树树转化为后序树
 * @param A 前序树
 * @param l1
 * @param h1
 * @param B 后续树
 * @param l2
 * @param h2
 */
void Pre2Post(int A[], int l1, int h1, int B[], int l2, int h2);

/**
 * 二叉树的叶节点从左到到右连接为链表
 * @param root 根节点
 */
void Left2Right(BinaryTreeNode *root);

/**
 * 判断两棵二叉树是否形状相似
 * @param root1 根节点1
 * @param root2 根节点2
 * @return 逻辑值
 */
int IsSimilar(BinaryTreeNode *root1, BinaryTreeNode *root2);


/**
 * 在中序线索树种查找p的后序前驱节点
 * @param root 根节点
 * @param p 要查找的节点
 * @return 查找到的节点
 */
ThreadedTree InPostPre(ThreadedTree *root, ThreadedTree *p);


/**
 * 表达式二叉树转化为表达式
 * @param root 根节点
 */
void Btree2Expr(Expr *root, int deep);

/**
 * 二叉树对称序线索化
 * @param root 根节点
 */
void InorderTheadedtree(BinaryTreeNode *root);



#endif //DATA_STRUCTURE_BINARYTREE_H
