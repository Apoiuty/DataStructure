#include <stdio.h>
#include <limits.h>
#include "BinaryTree/BinaryTree.h"
#include "BinaryTree/BinarySTree.h"
#include "BinaryTree/maxHeap.h"
#include "Graph/graph.h"

int main() {
    int n = 3;
    int path[3][3];
    int adj[3][3] = {{0, 4,     11},
                     {6, 0,     2},
                     {3, 32767, 0}};
    int D[3][3];
    Floyd(3, D, path, adj);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf("%d ", D[i][j]);
            if (j == 2)
                printf("\n");
        }
    }
    for (int i = 0; i < n; i++) {
        for (int l = 0; l < n; ++l) {
            printf("%d ", path[i][l]);
            if (l == 2)
                printf("\n");
        }
    }
}


