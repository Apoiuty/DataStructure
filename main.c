#include <stdio.h>
#include "BinaryTree/BinaryTree.h"

int main() {
    BinaryTreeNode *root1 = CreatBinaryTreeN(7), *root2 = CreatBinaryTreeN(7);
    printf("%d", IsSimilar(root1, root2));
    return 0;
}


