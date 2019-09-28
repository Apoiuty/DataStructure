#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include "Linked_List/NodeLib.h"
#include "Linked_List/linkedlist.h"
#include "Linked_List/WangDao2.h"
#include "String/String.h"
#include <string.h>

int main() {
    Node *a=CreatL(20),*b=CreatL(15);
    PrintOutL(a);
    PrintOutL(b);
    int po = 2;
    int jj = 25;
        printf("%d",Find_k(a,25));
    return 0;
}

