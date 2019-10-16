#include <stdio.h>
#include "BinaryTree/BinaryTree.h"
#include "BinaryTree/BinarySTree.h"
#include "BinaryTree/maxHeap.h"

int main() {
    int A[] = {9, 8, 7, 1, 6, 4, 5};
    printf("%d", IsMaxHeap(A, sizeof(A) / sizeof(int)));
    return 0;
}


