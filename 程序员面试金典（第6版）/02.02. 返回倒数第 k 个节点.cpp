/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    int kthToLast(ListNode *head, int k) {
        ListNode *tail = head;
        while (k > 0 && tail) {
            tail = tail->next;
            k--;
        }

        while (tail) {
            head = head->next;
            tail = tail->next;
        }

        return head->val;
    }
};