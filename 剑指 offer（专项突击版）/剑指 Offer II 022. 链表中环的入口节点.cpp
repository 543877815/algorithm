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
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        do {
            if (!fast || !fast->next) return NULL;
            else {
                slow = slow->next;
                fast = fast->next->next;
            }
        } while (slow != fast);

        ListNode *curr = head;
        while (curr != slow) {
            curr = curr->next;
            slow = slow->next;
        }
        return curr;
    }
};