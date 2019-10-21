#include <stdio.h>
#include <limits.h>
#include "BinaryTree/BinaryTree.h"
#include "BinaryTree/BinarySTree.h"
#include "BinaryTree/maxHeap.h"
#include "Graph/graph.h"

int main() {
    int adj[7][7] = {{0,       3,       3,       6,       INT_MAX, INT_MAX, INT_MAX},
                     {INT_MAX, 0,       4,       INT_MAX, 5,       INT_MAX, INT_MAX},
                     {INT_MAX, INT_MAX, 0,       INT_MAX, 4,       INT_MAX, INT_MAX},
                     {INT_MAX, INT_MAX, INT_MAX, 0,       INT_MAX, 5,       INT_MAX},
                     {INT_MAX, INT_MAX, INT_MAX, INT_MAX, 0,       INT_MAX, 3},
                     {INT_MAX, INT_MAX, 3,       INT_MAX, INT_MAX, 0,       7},
                     {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 0}
    };
    Graph *g = Adj2Grapg(7, adj);
    dfsTopSort(g);
    return 0;

}


