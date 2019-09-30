#include "Sort/sort.h"

int main() {
    ForSort A[20];
    Initialization(A, 20);
    PrintSorted(A, 20);

    QuickSort(A, 0,19);
    PrintSorted(A, 20);
    return 0;
}


