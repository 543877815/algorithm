/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    ListNode *removeDuplicateNodes(ListNode *head) {
        if (!head) return head;
        unordered_set<int> occurred = {head->val};
        ListNode *pre = head;
        while (pre->next) {
            ListNode *curr = pre->next;
            if (!occurred.count(curr->val)) {
                occurred.insert(curr->val);
                pre = pre->next;
            } else {
                pre->next = pre->next->next;
            }
        }
        return head;
    }
};