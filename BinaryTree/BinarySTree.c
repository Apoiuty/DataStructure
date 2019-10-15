//
// Created by Apoiuty on 2019/10/14.
//

#include <time.h>
#include "BinarySTree.h"


/**
 * 将tar插入到二叉排序树中去
 * @param root 根节点
 * @param tar target
 */
void InsertSTreeNode(BinaryTreeNode **root, BinaryTreeNode *tar) {
//    如果为空树直接作为根节点插入
    if (*root == NULL)
        *root = tar;
    else if ((*root)->data < tar->data)
        InsertSTreeNode(&(*root)->right, tar);
    else {
        InsertSTreeNode(&(*root)->left, tar);
    }
}


/**
 * 创建有n个节点的二叉排序树
 * @param n
 */
BinaryTreeNode *CreatBSTreeN(int n) {
    srand(time(0));

//    生成根节点
    n--;
    BinaryTreeNode *root = (BinaryTreeNode *) malloc(sizeof(BinaryTreeNode));
    root->data = rand() % n + 1;
    root->left = root->right = NULL;

    BinaryTreeNode *cur, *new, *pre;
    while (n) {
        new = (BinaryTreeNode *) malloc(sizeof(BinaryTreeNode));
        new->data = rand() % n + 1;
        new->left = new->right = NULL;
        cur = root, pre = NULL;
//        比根节点大向右遍历
        while (cur) {
            if (cur->data < new->data) {
                pre = cur;
                cur = cur->right;
            } else {
                pre = cur;
                cur = cur->left;
            }
        }
        if (pre->data < new->data) {
            pre->right = new;
        } else {
            pre->left = new;
        }
        n--;
    }

    return root;
}


/**
 * 删除二叉排序树的tar节点, par为父节点
 * @param root
 * @param tar
 * @param par
 */
void Delete_bst(BinaryTreeNode *root, BinaryTreeNode *tar, BinaryTreeNode *par) {
    if (tar->right == NULL) {
        if (par == NULL) {
            root = tar->left;
        } else if (par->left == tar) {
            par->left = tar->right;
        } else {
            par->right = tar->right;
        }

    } else if (tar->left == NULL) {
        if (par == NULL) {
            root = tar->right;
        } else {
            if (par->left == tar) {
                par->left = tar->right;
            } else {
                par->right = tar->right;
            }
        }
    } else {
        BinaryTreeNode *pre = tar->right;
        while (pre->right)
            pre = pre->right;
        pre->right = tar;

        if (par == NULL) {
            root = tar->left;
        } else {
            if (par->left == tar) {
                par->left = tar->left;
            } else {
                par->right = tar->left;
            }
        }
    }
}


/**
 * AVL树中插入节点
 * @param root 根节点
 * @param p 要插入的节点
 */
void Insert_AVL(AVL **ROOT, AVL *p) {
    AVL *root = *ROOT;
    AVL *cur, *pre;
    cur = root;
    while (cur) {
//        插入节点
        pre = cur;
        if (cur->data < p->data) {
            cur = cur->right;
        } else {
            cur = cur->left;
        }
    }

    p->parent = pre;
    if (pre->data < p->data) {
        pre->right = p;
    } else {
        pre->left = p;
    }

//        修改平衡因子并寻找失衡节点
//          修改父节点平衡因子
    if (pre->left == p) {
        pre->balence++;
    } else
        pre->balence--;


    cur = pre;
    if (pre->left == NULL || pre->right == NULL) {
        while (cur && cur->parent) {
            if (cur->parent->left == cur) {
                cur->parent->balence++;
            } else {
                cur->parent->balence--;
            }
            if (cur->parent->balence < -1 || cur->parent->balence > 1) {
                cur = cur->parent;
                break;
            }
            cur = cur->parent;
        }
    }


//    是否是失衡节点
    if (cur->balence >= -1 && cur->balence <= 1)
        return;


//    LL翻转
    AVL *son, *grandson;
    if (cur->balence == 2) {
        son = cur->left;
        if (cur->left->balence == 1) {
            if (cur->parent) {
                if (cur->parent->left == cur) {
                    cur->parent->left = son;
                } else {
                    cur->parent->right = son;
                }
            }


            cur->balence = cur->left->balence = 0;
            cur->left = cur->left->right;
            son->right = cur;
            son->parent = cur->parent;
            cur->parent = son;

            if (son->parent == NULL) {
                *ROOT = son;
            }
//            LR翻转
        } else if (cur->left->balence == -1) {
            grandson = son->right;

            if (cur->parent) {
                if (cur->parent->left == cur) {
                    cur->parent->left = grandson;
                } else {
                    cur->parent->right = grandson;
                }
            }


            son->parent = grandson;
            son->right = grandson->left;

            grandson->parent = cur->parent;
            cur->parent = grandson;
            cur->left = grandson->right;

            grandson->left = son;
            grandson->right = cur;

            if (grandson->balence == 1) {
                son->balence = grandson->balence = 0;
                cur->balence = -1;
            } else if (grandson->balence == 0) {
                grandson->balence = son->balence = cur->balence = 0;
            } else if (grandson->balence == -1) {
                grandson->balence = cur->balence = 0;
                son->balence = 1;
            }

            if (grandson->parent == NULL) {
                *ROOT = grandson;
            }

        }
    } else {
//        RR翻转
        son = cur->right;
        if (son->balence == -1) {
            if (cur->parent) {
                if (cur->parent->left == cur) {
                    cur->parent->left = son;
                } else {
                    cur->parent->right = son;
                }
            }

            son->parent = cur->parent;
            cur->parent = son;

            cur->right = son->left;
            son->left = cur;

            son->balence = cur->balence = 0;

            if (son->parent == NULL) {
                *ROOT = son;
            }
        } else {
//            RL翻转

            grandson = son->left;
            if (cur->parent) {
                if (cur->parent->left == cur) {
                    cur->parent->left = grandson;
                } else {
                    cur->parent->right = grandson;
                }
            }

            grandson->parent = cur->parent;
            cur->right = grandson->left;
            son->left = grandson->right;

            cur->parent = grandson;
            son->parent = grandson;
            grandson->left = cur;
            grandson->right = son;


            if (grandson->balence == -1) {
                son->balence = grandson->balence = 0;
                cur->balence = +1;
            } else if (grandson->balence == 0) {
                grandson->balence = son->balence = cur->balence = 0;
            } else if (grandson->balence == +1) {
                grandson->balence = cur->balence = 0;
                son->balence = -1;
            }
            if (grandson->parent == NULL) {
                *ROOT = son;
            }
        }
    }


}


/**
 * 前序遍历二叉树
 * @param root 根节点
 */
void Printout_AVL(AVL *root) {
    if (root) {
        printf("(%d,%d) ", root->data, root->balence);
        Printout_AVL(root->left);
        Printout_AVL(root->right);
        if (root->parent == NULL) {
            printf("\n");
        }
    }
}


/**
 * 获取平衡二叉树的高度
 * @param root 根节点
 * @return 高度值
 */
int Get_AVLHeight(AVL *root) {
    if (root) {
        int h1 = Get_AVLHeight(root->left);
        int h2 = Get_AVLHeight(root->right);
        return h1 > h2 ? h1 + 1 : h2 + 1;
    } else {
        return 0;
    }
}
