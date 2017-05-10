/**
 * You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
 *
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 *
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* result = l1;
    if (l1 == NULL) {
        return l2;
    }
    if (l2 == NULL) {
        return l1;
    }
    int jinwei = 0;
    ListNode* pre = NULL;
    while (l1 && l2) {
        l1->value = l1->value + l2->value;
        jinwei = (l1->value + l2->value) / 10;
        l1->value = (l1->value + l2->value) % 10;
        pre = l1;
        l1 = l1->next;
        l2 = l2->next;
    }
    if (l1) {
        while (jinwei) {
            if (l1 == NULL) {
                l1 = new ListNode;
                l1->val = jinwei;
                l1->next = NULL;
                pre->next = l1;
                break;
            }
            l1->val = l1->val + jinwei;
            jinwei = l1->val / 10;
            l1->val = l1->val % 10;
            pre = l1;
            l1 = l1->next;
        }
    } else if (l2) {
        l2->val = l2->val + jinwei;
        jinwei = l2->val / 10;
        l2->val = l2->val % 10;
        pre->next = l2;
        pre = l2;
        l2 = l2->next;
        while (jinwei) {
            if (l2 == NULL) {
                l2 = new ListNode;
                l2->val = jinwei;
                l2->next = NULL;
                pre->next = l2;
                break;
            }
            l2->val = l2->val + jinwei;
            jinwei = l2->val / 10;
            l2->val = l2->val % 10;
            pre = l2;
            l2 = l2->next;
        }
    } else if (jinwei) {
        pre->next = new ListNode;
        pre->next->val = jinwei;
        pre->next->next = NULL;
    }

    return head;
}
