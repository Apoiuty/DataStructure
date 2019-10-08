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
int IsEmptyTree(BinaryTree *bt) {
    return bt->root == NULL;
}

/**
 * 返回二叉树根节点的值
 * @param bt
 * @return 根节点值
 */
int GetRoot(BinaryTree *bt) {
    if (!IsEmptyTree(bt)) {
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

/**
 * 前序遍历二叉树(非递归)
 * @param root 根节点
 */
void NLR(BinaryTreeNode *root) {
    BinaryTreeNode *stack[100];
    unsigned top = 0;
    stack[0] = root;
    do {
//        一直输出到最左边的树
        while (stack[top]) {
            printf("%d ", stack[top]->data);
            stack[++top] = stack[top]->left;
        }
//        尝试转到上一层的右子树
        if (top > 0) {
            stack[top] = stack[--top]->right;
        }
    } while (stack[top] || top);
}

/**
 * 对称序遍历二叉树
 * @param root 根节点
 */
void LNR(BinaryTreeNode *root) {
    BinaryTreeNode *stack[100];
    unsigned top = 0;
    stack[0] = root;
    do {
//        一直遍历到最左边子树
        while (stack[top])
            stack[++top] = stack[top]->left;

//        输出左子树, 根节点和右子树
        if (top) {
            printf("%d ", stack[--top]->data);
            stack[top] = stack[top]->right;
        }

    } while (top || stack[top]);
}

/**
 * 后序遍历二叉树
 * @param root 根节点
 */
void LRN(BinaryTreeNode *root) {
    unsigned tag[100];
    BinaryTreeNode *stack[100];
    unsigned top = 0;
    stack[0] = root;
    tag[0] = 0;

    do {
//        访问到最左边的节点
        while (stack[top]) {
            stack[++top] = stack[top]->left;
            tag[top] = 0;
        }

//        如果上一节点的右子节点已经输出则打印其节点
        while (tag[top - 1] == 1) {
            printf("%d", stack[--top]->data);

            if (top) {
                stack[top] = stack[top - 1]->right;
                tag[top - 1] = 1;
                tag[top] = 0;
            }
        }
    } while (top);
}

/**
 * 线索化二叉树的中序遍历算法
 * @param root
 * @param pre
 */
void InorderThreaded(ThreadedTree *root, ThreadedTree **pre) {
    if (root) {
//        左子树递归
        InorderThreaded(root->left, pre);

        if ((*pre) && (*pre)->rtag == 1)
            (*pre)->right = root;

//        左子树为空
        if (root->left == NULL) {
            root->ltag = 1;
            root->left = (*pre);
        }

//        右子树为空
        if (root->right == NULL)
            root->rtag = 1;

//        处理右子树
        *pre = root;
        InorderThreaded(root->right, pre);
    }
}

/**
 * 返回指定节点的对称后继节点值
 * @param p 指定节点
 * @return 后继节点的data
 */
int Inordernext(ThreadedTree *p) {
    if (p->rtag == 1)
        return p->right->data;
    else {
        p = p->right;
        while (p->ltag == 0)
            p = p->left;

        return p->data;
    }
}

/**
 * 对称序列遍历线索化二叉树
 * @param root 根节点
 */
void ThreadedInTravel(ThreadedTree *root) {
    if (root) {
        while (root->ltag == 0)
            root = root->left;

        do {
            printf("%d ", root->data);
            if (root->right)
                root = root->right;
            else {
                root = root->right;
                while (root->ltag == 0) {
                    root = root->left;
                }
            }

        } while (root);

    }
}


/**
 * 在对称序列化二叉树节点p后插入insert
 * @param p
 * @param insert
 */
void InsertThreadedTree(ThreadedTree *p, ThreadedTree *insert) {
    ThreadedTree *right_p;
    if (p->right == NULL)
        right_p = NULL;
    else {
//        找到p的后继节点
        if (p->rtag == 1)
            right_p = p->right;
        else {
            right_p = p->right;
            while (p->ltag == 0)
                right_p = right_p->left;
        }
    }

//    新建连接
    insert->ltag = 1;
    insert->left = p;
    insert->right = p->right;
    insert->rtag = p->rtag;

    p->rtag = 0;
    p->right = insert;
//    是否有后继节点
    if (right_p && right_p->ltag == 1)
        right_p->left = insert;

}