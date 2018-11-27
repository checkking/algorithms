/*
 * 反转一个列表
 *
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct LNode {
    int val;
    struct LNode* next;
} Node;

Node* reverse(Node *head) {
    Node* pre = NULL;
    Node* cur = head;
    Node* next = NULL;
    while (cur != NULL) {
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
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

    head = reverse(head);
    print(head);

    return 0;
}
