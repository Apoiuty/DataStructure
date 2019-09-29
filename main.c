#include "Sort/sort.h"

int main() {
    ForSort A[10];
    Initialization(A, 10);
    PrintSorted(A, 10);

    DirectSelection(A, 10);
    PrintSorted(A, 10);
    return 0;
}

