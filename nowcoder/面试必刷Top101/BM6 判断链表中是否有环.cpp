/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 // 快慢指针
 // 时间复杂度：O(n)
 // 空间复杂度：O(1)
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast) {
            slow = slow->next;
            fast = fast->next;
            if (fast) fast = fast->next;
            else break;
            if (slow == fast) return true;
        }

        return false;
    }
};