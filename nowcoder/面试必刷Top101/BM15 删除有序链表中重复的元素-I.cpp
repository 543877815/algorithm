/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    /**
     *
     * @param head ListNode类
     * @return ListNode类
     */
    ListNode *deleteDuplicates(ListNode *head) {
        // write code here
        ListNode *dummyHead = new ListNode(-1);
        dummyHead->next = head;
        ListNode *pre = dummyHead;
        ListNode *curr = head;
        while (curr && curr->next) {
            if (curr->val == curr->next->val) {
                while (curr && curr->next && curr->val == curr->next->val)
                    curr = curr->next;
                pre->next = curr;
            }
            pre = curr;
            curr = curr->next;
        }
        return dummyHead->next;
    }
};