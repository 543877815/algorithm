// 时间复杂度：O(n)
// 空间复杂度：O(1)

 /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;
        ListNode* curr = head;
        ListNode* next = curr->next;
        while(curr->next) {
            if (curr->val == next->val) {
                curr->next = next->next;
                next = curr->next;
            } else {
                curr = next;
                next = curr->next;
            }
        }
        return head;
    }
};