#include <stdio.h>
#include "BinaryTree/BinaryTree.h"

int main() {
    BinaryTreeNode *root = CreatBinaryTreeN(20);
    PreOrder(root);
    printf("\n");
    NLR(root);
    printf("\n");

    LNR(root);
    printf("\n");
    InOrder(root);
    printf("\n");

    PostOrder(root);
    printf("\n");
    PostOrder2(root);

    printf("\n");
    Inverse_LevelOrder(root);

    printf("\n%d", GetTreeHeight(root));

    return 0;


}


