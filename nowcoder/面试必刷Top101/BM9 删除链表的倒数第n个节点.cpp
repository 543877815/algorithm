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
     * @param n int整型
     * @return ListNode类
     */
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // write code here
        if (!head) return nullptr;
        ListNode *dummyHead = new ListNode(-1);
        dummyHead->next = head;
        int num = 0;
        ListNode *curr = head;
        while (curr) {
            curr = curr->next;
            num++;
        }
        if (num < n) return head;
        num -= n;
        curr = head;
        ListNode *pre = dummyHead;
        while (num > 0) {
            curr = curr->next;
            pre = pre->next;
            num--;
        }
        pre->next = curr->next;
        curr->next = nullptr;
        return dummyHead->next;
    }
};