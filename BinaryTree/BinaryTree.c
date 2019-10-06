//
// Created by Apoiuty on 2019/10/6.
//

#include <time.h>
#include "BinaryTree.h"

#define ALLOC_FAIL "Allocation failure.\n"
#define N 100

/**
 * 二叉树节点初始化函数
 * @param btree 要初始化的节点
 * @param left 左子节点
 * @param right 右子节点
 * @param data 数据项
 */
void InitBinaryTreeNode(BinaryTreeNode *btree, BinaryTreeNode *left, BinaryTreeNode *right, int data) {
    btree->data = data;
    btree->left = left;
    btree->right = right;
}

/**
 * 创建二叉树节点
 * @param left 左子节点
 * @param right 右子节点
 * @param data 数据
 * @return 创建好的节点
 */
BinaryTreeNode *CreatBinaryTreeNode(BinaryTreeNode *left, BinaryTreeNode *right, int data) {
    BinaryTreeNode *target = (BinaryTreeNode *) malloc(sizeof(BinaryTreeNode));
    if (target) {
        target->data = data;
        target->left = left;
        target->right = right;
    } else {
        printf("Memeory alllocation failure.\n");
        exit(1);
    }
    return target;
}

/**
 * 初始化二叉树结构
 * @param bt 要初始化的树
 */
void InitBinaryTree(BinaryTree *bt) {
    bt->root = NULL;
}

/**
 * 判断二叉树是否为空
 * @param bt 二叉树
 * @return
 */
int IsEmpty(BinaryTree *bt) {
    return bt->root == NULL;
}

/**
 * 返回二叉树根节点的值
 * @param bt
 * @return 根节点值
 */
int GetRoot(BinaryTree *bt) {
    if (!IsEmpty(bt)) {
        return bt->root->data;
    } else {
        printf("Tree bt is empty.\n");
        exit(1);
    }
}

/**
 * 构造二叉树
 * @param bt 二叉树根节点
 * @param left 左子节点
 * @param right 右子节点
 * @param data 数据项
 * @return 构造的二叉树
 */
BinaryTreeNode *MakeTree(BinaryTree *bt, BinaryTreeNode *left, BinaryTreeNode *right, int data) {
    bt->root = (BinaryTreeNode *) malloc(sizeof(BinaryTreeNode));

    if (bt->root) {
        InitBinaryTreeNode(bt->root, left, right, data);
    } else {
        printf(ALLOC_FAIL);
        exit(1);
    }

    return bt->root;
}

/**
 * 前序遍历二叉树
 * @param root 根节点
 */
void PreOrder(BinaryTreeNode *root) {
    if (root) {
        printf("%d ", root->data);
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

/**
 * 后序遍历二叉树
 * @param root 根节点
 */
void PostOrder(BinaryTreeNode *root) {
    if (root) {
        PostOrder(root->left);
        PostOrder(root->right);
        printf("%d ", root->data);
    }
}

/**
 * 中序遍历二叉树
 * @param root 根节点
 */
void InOrder(BinaryTreeNode *root) {
    if (root) {
        InOrder(root->left);
        printf("%d ", root->data);
        InOrder(root->right);
    }
}

