//
// Created by Apoiuty on 2019/9/25.
//

#include "WangDao2.h"

//删除不含头结点的单链表L中x的递归算法
void Delte_x(Node *head, int x, Node *pre) {
    Node *p;
    if (head == NULL) {
//        空链表
        return;
    } else {
        if (head->data == x) {
//                如果在头部删除
            if (pre == NULL) {
                pre = head->next;
            } else {
//                在中间删除
                pre->next = head->next;
            }

            p = head;
            head = head->next;
            free(p);
            Delte_x(head, x, pre);

        } else {
//            不删除节点递归
            Delte_x(head->next, x, head);
        }
    }
}

//删除含头结点的单链表L中x的递归算法
void WithHead_Delte_x(Node *head, int x, Node *pre) {
//    pre为前一个节点, head为第一个节点;
    if (head == NULL)
//        结束递归
        return;
    else {
        if (head->data == x) {
//            删除节点
            Node *temp;
            temp = head;
            pre->next = head->next;
            head = head->next;
            free(temp);
            WithHead_Delte_x(head, x, pre);
        } else {
//            保留节点
            WithHead_Delte_x(head->next, x, head);
        }
    }
}

//反向输出各节点的值
void Inverse_Output(Node *head) {
//    head为第一个节点
    if (head) {
        if (head->next) {
            Inverse_Output(head->next);
        }
        printf("%d ", head->data);
    }
}

//删除链表中的最小元素
void Delete_Min(Node *head) {
    Node *pre, *cur, *pmin, *ppre;
    int min;

    if (head->next == NULL) {
        printf("The linkedlist is empty.\n");
        exit(1);
    }

    cur = head->next;
    pre = head;
    min = cur->data;
    pmin = cur;
    ppre = pre;

    while (cur) {
        if (cur->data < min) {
            min = cur->data;
            pmin = cur;
            ppre = pre;
        }
        pre = cur;
        cur = cur->next;
    }

    ppre->next = pmin->next;
    free(pmin);

}

//带头结点的就地转置
void Inverse_Withhead(Node *head) {
    if (head->next == NULL) {
        return;
    }
//    空链表

    Node *pre, *cur, *nnext;
//    pre, 前一个;cur, 正在处理的; nnext, 下一个
    pre = head->next;
    cur = pre->next;
    pre->next = NULL;
    while (cur) {
        nnext = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nnext;
    }
//head指向最后一个节点
    head->next = pre;
}

//插入递增排序
void Sort_WithHead(Node *head) {
    if (head->next == NULL) {
        return;
    }
//    空链表

    Node *cur, *next, *pre, *nnext;
    next = head->next->next;
    head->next->next = NULL;

    while (next) {
        nnext = next->next;
//        从第一个节点查找插入位置
        pre = head;
        cur = head->next;

        while (cur) {
            if (cur->data < next->data) {
//                如果不是插入位置
                pre = cur;
                cur = cur->next;
            } else {
                break;
            }
//            插入到pre后面; 如果cur是空则插入到尾部
        }
        pre->next = next;
        next->next = cur;
//            查找下一个节点
        next = nnext;
    }

}

//删除介于m和M之间的值
void Delete_mM(Node *head, int m, int M) {
    Node *pre, *cur, *next;

    for (pre = head, cur = head->next; cur;) {
        if (cur->data > m && cur->data < M) {
            pre->next = cur->next;
            next = cur->next;
            free(cur);
            cur = next;
//            如果要删除cur就不要改变pre的值
        } else {
            pre = cur;
            cur = cur->next;
        }
    }

}

//寻找单链表公共节点
Node *Find_Common_Node(Node *head1, Node *head2) {
    int len1, len2, diff;
    len1 = Length_WithHead(head1);
    len2 = Length_WithHead(head2);
    diff = len1 - len2;

    if (diff > 0) {
        while (diff) {
            head1 = head1->next;
            diff--;
        }
    } else if (diff < 0) {
        while (diff) {
            head2 = head2->next;
            diff++;
        }
    }

    while (head1 != head2 && head1 && head2) {
        head1 = head1->next, head2 = head2->next;
    }

    return head1;
}

//带头结点链表长度
int Length_WithHead(Node *head) {
    int cnt = 0;

    Node *cur = head->next;
    while (cur) {
        cnt++;
        cur = cur->next;
    }
    return cnt;
}

//输出递增顺序的链表并释放存储空间
void Min_Delete(Node *head) {
    Node *pre, *ppmin, *pmin, *cur;
    int min;

    while (head->next) {
        pre = head;
        pmin = pre->next;
        ppmin = head;
        min = pmin->data;
        cur = head->next;

        while (cur) {
            if (cur->data < min) {
                pmin = cur;
                ppmin = pre;
            }
            pre = cur;
            cur = pre->next;
        }

        ppmin->next = pmin->next;
        printf("%d ", pmin->data);
        free(pmin);

    }
}

//将一个链表L分为两个链表a和b, a为奇数元素, b中为偶数元素
void DisCreat_1(Node *L, Node **a, Node **b) {
//    修改两个指针变量的值需要指针的地址

    int cnt = 0;
    Node *cur = L->next, *new, *cur1, *cur2;
    *a = (Node *) malloc(sizeof(Node));
    *b = (Node *) malloc(sizeof(Node));
    (*a)->next = NULL;
    (*b)->next = NULL;
    cur1 = *a, cur2 = *b;

    while (cur) {
//        分配节点
        cnt++;
        new = (Node *) malloc(sizeof(Node));
        new->data = cur->data;
        new->next = NULL;

        if (cnt % 2) {
            cur1->next = new;
            cur1 = new;
        } else {
            cur2->next = new;
            cur2 = new;
        }
//        迭代
        cur = cur->next;
    }
}

//将一个链表L分为两个链表a和b, a为奇数元素, b中为偶数元素
void DisCreat_2(Node *L, Node **a, Node **b) {
//    修改两个指针变量的值需要指针的地址

    int cnt = 0;
    Node *cur = L->next, *new, *cur1, *cur2;
    *a = (Node *) malloc(sizeof(Node));
    *b = (Node *) malloc(sizeof(Node));
    (*a)->next = NULL;
    (*b)->next = NULL;
    cur1 = *a, cur2 = *b;

    while (cur) {
//        分配节点
        cnt++;
        new = (Node *) malloc(sizeof(Node));
        new->data = cur->data;
        new->next = NULL;

        if (cnt % 2) {
            cur1->next = new;
            cur1 = new;
        } else {
            new->next = (*b)->next;
            (*b)->next = new;
        }
//        迭代
        cur = cur->next;
    }
}

//删除有序表中相同的元素
void Delete_Same(Node *head) {
    Node *cur, *next, *temp;
    cur = head->next;
    while (cur) {
//        查找下一个不同节点
        next = cur->next;
        while (next && next->data == cur->data) {
            temp = next->next;
            free(next);
            next = temp;
        }
//        拼接下一个不同节点
        cur->next = next;
        cur = cur->next;
    }
}

//合并递增双链表和递减单链表
Node *MergeList(Node *a, Node *b) {
    Node *head, *cura, *curb, *new;
    head = (Node *) malloc(sizeof(Node));
    head->next = NULL;
    cura = a->next, curb = b->next;

    while (cura && curb) {
        new = (Node *) malloc(sizeof(Node));
        if (cura->data < curb->data) {
            new->data = cura->data;
            new->next = head->next;
            head->next = new;
            cura = cura->next;
        } else {
            new->data = curb->data;
            new->next = head->next;
            head->next = new;
            curb = curb->next;
        }
    }
//    插入剩余元素
    if (cura) {
        while (cura) {
            new = (Node *) malloc(sizeof(Node));
            new->data = cura->data;
            new->next = head->next;
            head->next = new;
            cura = cura->next;
        }
    } else if (curb) {
        while (curb) {
            new = (Node *) malloc(sizeof(Node));
            new->data = curb->data;
            new->next = head->next;
            head->next = new;
            curb = curb->next;
        }
    }
    return head;
}

//产生a, b两链表公共元素链表C
Node *Get_Common(Node *a, Node *b) {
    Node *cura = a->next, *curb = b->next;

    Node *new, *c = (Node *) malloc(sizeof(Node));
    c->next = NULL;

//    谁小谁递增
    while (cura && curb) {
        if (cura->data > curb->data) {
            curb = curb->next;
        } else if (cura->data < curb->data) {
            cura = cura->next;
        } else {
            new = (Node *) malloc(sizeof(Node));
            new->data = cura->data;
            new->next = c->next;
            c->next = new;
            cura = cura->next, curb = curb->next;
        }
    }

    return c;
}

//b链表是否是a链表的连续子序列
int Pattern(Node *a, Node *b) {
    Node *cura = a->next, *curb = b->next;
    int Lena = Length_WithHead(a), lenb = Length_WithHead(b);
    Node *heada = a->next;

    for (int i = 0; i <= Lena - lenb; ++i) {
        cura = heada;
        curb = b->next;
        while (curb && cura->data == curb->data) {
            cura = cura->next;
            curb = curb->next;
        }

        if (curb == NULL)
            return 1;
        heada = heada->next;
    }

    return -1;
}

//判断双循环链表是否对称
int Symmety(DNode *head) {
    DNode *front = head->next, *rear = head->pre;
    while (front->data == rear->data && front->next != rear && front != rear) {
        front = front->next;
        rear = rear->pre;
    }

    if (front->next == rear || front == rear) {
        return 1;
    } else {
        return 0;
    }
}

//将b链表接到a链表之后, a b均为循环单链表
void Link(Node *a, Node *b) {
    Node *rear_a = a;
    while (rear_a->next != a) {
        rear_a = rear_a->next;
    }

    Node *rear_b = b;
    while (rear_b->next != a) {
        rear_b = rear_b->next;
    }

    rear_a->next = b;
    rear_b->next = a;

}

//返回元素为x的双向链表的位置
FNode *Locate(FNode *head, int x) {
    FNode *cur, *re;
    cur = head->next;

    while (cur) {
        if (cur->data == x)
            break;
        cur = cur->next;
    }

    if (cur) {
        re = cur;
        re->fre++;

//        摘下
        re->pre->next = re->next;
        if (re->next)
            re->next->pre = re->pre;

//        寻找前驱节点
        cur = re->pre;
        while (cur != head && cur->fre <= re->fre)
            cur = cur->pre;
        re->next = cur->next;
        cur->next->pre = re;
        re->pre = cur;
        cur->next = re;
        return re;
    } else {
        return NULL;
    }
}

//寻找倒数第k位置的链表元素
int Find_k(Node *head, int k) {
    Node *pre, *rear;

    if (head->next) {
        pre = rear = head->next;
    } else {
        printf("Empty LinkedList.\n");
    }

    int cnt = 0;
    while (rear) {
        if (cnt < k)
            cnt++;
        else
            pre = pre->next;

        rear = rear->next;
    }

    if (cnt < k) {
        printf("K is too big.\n");
    } else {
        return pre->data;
    }

    return pre->data;
}
