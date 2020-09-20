
#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *initNode(int val)
{
    struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
    if (!node)
    {
        printf("error");
    }
    node->val = val;
    node->next = NULL;
    return node;
}

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode *head = initNode(-1);
    struct ListNode *temp = head;
    int tens_digit = 0;
    while (l1 || l2)
    {
        int val1 = l1 == NULL ? 0 : l1->val;
        int val2 = l2 == NULL ? 0 : l2->val;
        int units_digit = (val1 + val2 + tens_digit) % 10;
        tens_digit = (val1 + val2 + tens_digit) / 10;
        struct ListNode *node = initNode(units_digit);
        temp->next = node;
        temp = temp->next;
        if (l1)
            l1 = l1->next;
        if (l2)
            l2 = l2->next;
    }
    if (tens_digit)
        temp->next = initNode(1);
    return head->next;
}