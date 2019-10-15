//
// Created by Apoiuty on 2019/10/14.
//

#ifndef DATA_STRUCTURE_BINARYSTREE_H
#define DATA_STRUCTURE_BINARYSTREE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "BinaryTree.h"

//AVL tree
struct avltree {
    int data;
    int balence;
    struct avltree *left, *right, *parent;
};

typedef struct avltree AVL;

/**
 * AVL树中插入节点
 * @param ROOT 根节点
 * @param p 要插入的节点
 */
void Insert_AVL(AVL **ROOT, AVL *p);


/**
 * 将tar插入到二叉排序树中去
 * @param root 根节点
 * @param tar target
 */
void InsertSTreeNode(BinaryTreeNode **root, BinaryTreeNode *tar);

/**
 * 创建有n个节点的二叉排序树
 * @param n
 */
BinaryTreeNode *CreatBSTreeN(int n);

/**
 * 删除二叉排序树的tar节点, par为父节点
 * @param root
 * @param tar
 * @param par
 */
void Delete_bst(BinaryTreeNode *root, BinaryTreeNode *tar, BinaryTreeNode *par);

/**
 * 前序遍历二叉树
 * @param root 根节点
 */
void Printout_AVL(AVL *root);


/**
 * 获取平衡二叉树的高度
 * @param root 根节点
 * @return 高度值
 */
int Get_AVLHeight(AVL *root);

#endif //DATA_STRUCTURE_BINARYSTREE_H

