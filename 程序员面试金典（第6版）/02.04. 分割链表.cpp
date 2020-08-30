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
    ListNode *partition(ListNode *head, int x) {
        ListNode *curr = head;
        int less = 0;
        while (curr) {
            if (curr->val < x) less++;
            curr = curr->next;
        }

        ListNode *right = head;
        ListNode *left = head;
        while (less > 0) {
            less--;
            right = right->next;
        }

        while (right && left) {
            while (left && left->val < x) {
                left = left->next;
            }
            while (right && right->val >= x) {
                right = right->next;
            }
            if (left && right) swap(left->val, right->val);
        }

        return head;
    }
};