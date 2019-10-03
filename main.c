#include "Sort/sort.h"
#include <stdio.h>
#include "Sort/WangDao7.h"

int main() {
    ForSort A[20];
    Initialization(A, 20);
    PrintSorted(A, 20);
    Flag_Arrange(A, 20);
    PrintSorted(A, 20);
    return 0;
}


