#include <stdio.h>
#include "BinaryTree/BinaryTree.h"
#include "BinaryTree/BinarySTree.h"

int main() {
    AVL *root = (AVL *) malloc(sizeof(AVL));
    root->data = 12;
    root->left = root->right = root->parent = NULL;
    root->balence = 0;

    AVL *new;
    int A[] = {22, 31, 56, 50};
    for (int i = 0; i < 4; ++i) {
        new = (AVL *) malloc(sizeof(AVL));
        new->balence = 0;
        new->parent = new->left = new->right = NULL;
        new->data = A[i];
        Insert_AVL(&root, new);
        Printout_AVL(root);
    }
    return 0;
}


