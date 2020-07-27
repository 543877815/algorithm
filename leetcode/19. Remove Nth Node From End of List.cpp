/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


// 先遍历一遍计算链表长度；再遍历一遍删除倒数第n个节点
// 时间复杂度：O(n)
// 空间复杂度：O(1)
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    if (head == NULL || head->next == NULL) return NULL;
    struct ListNode* slow = head;
    struct ListNode* fast = head -> next;
    int count = 0;
    while(fast) {
        fast = fast -> next;
        count ++;
    }
    fast = head -> next;
    while (count > n) {
        fast = fast -> next;
        slow = slow -> next;
        count--;
    }
    if (count == n) {
        slow ->next = fast ->next;
    } else {
        head = head -> next;
    }
    return head;
}

// 双指针
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        assert(n>=0);
        ListNode *dummyNode = new ListNode(0);
        dummyNode->next = head;

        ListNode *p = dummyNode, *q = dummyNode;

        for (int i = 0; i < n + 1; i++) {
            assert(q);
            q = q->next;
        }

        while(q) {
            p = p->next;
            q = q->next;
        }

        ListNode* delNode = p->next;
        p->next = delNode->next;
        delete delNode;

        ListNode *retNode = dummyNode->next;
        delete dummyNode;

        return retNode;

    }
};