#include "Sort/sort.h"
#include <stdio.h>
#include "Sort/WangDao7.h"

int main() {
    Node *head;
    head = CreatL(10);
    PrintOutL(head);

    MergeSortL(head, 1);
    PrintOutL(head);
    return 0;
}


