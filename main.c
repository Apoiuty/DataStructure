#include <stdio.h>
#include "BinaryTree/BinaryTree.h"
int main() {
    BinaryTree *bt;
    bt=(BinaryTree *)malloc(sizeof(BinaryTree));
    InitBinaryTree(bt);
    MakeTree(bt, NULL, NULL, 0);


}


