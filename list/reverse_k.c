/**
 * 单链表每隔k个元素做一次反转
 *
 */
#include <stdlib.h>
#include <stdio.h>

typedef struct LNode {
    int val;
    struct LNode* next;
} Node;

Node* rollback(Node* head, int k) {
    Node *pre = NULL;
    Node *cur = head;
    Node *next = NULL;
    int count = 0;
    if (head == NULL) {
        return NULL;
    }

    while (cur != NULL && count < k) {
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
        ++count;
    }

    if (cur != NULL) {
        head->next = rollback(next, k);
    }

    return pre;
}

void print(Node* head) {
    Node *cur = head;
    while (cur != NULL) {
        printf("%d ", cur->val);
        cur = cur->next;
    }
    printf("\n");
}

int main(int argc, char* argv[]) {
    Node *head = NULL;
    Node *cur = NULL;
    int i = 1;
    for (; i < 10; ++i) {
       Node *n = (Node*)malloc(sizeof(Node));
       n->next = NULL;
       n->val = i;
       if (head == NULL) {
           head = n;
           cur = head;
       } else {
           cur -> next = n;
           cur = n;
       }
    }
    print(head);

    head = rollback(head, 3);
    print(head);

    return 0;
}
