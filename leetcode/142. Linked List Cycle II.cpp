/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    if (head == NULL || head->next == NULL) return NULL;
    struct ListNode *p = head;
    struct ListNode *q = head->next;
    while (q && q->next) {
        p = p->next;
        q = q->next->next;
        if (q == NULL) return NULL;
        if (p == q) { // 判断有环
            struct ListNode *r = head;
            while (true) {
                q = q->next;
                if (p == q) return p; // 自环
                while (q != p) {
                    if (r == q || r == p) {
                        return r;
                    }
                    q = q->next;
                }
                r = r->next;
            }
        };
    }
    return NULL;
}


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// c++ 改进
// 空间复杂度：O(1)
// 时间复杂度：O(n)
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) return NULL;
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) break;
        }
        if (fast != slow) return NULL;
        fast = head;
        while (fast != slow) {
            slow = slow->next;
            fast = fast->next;
        }
        return fast;
    }
};