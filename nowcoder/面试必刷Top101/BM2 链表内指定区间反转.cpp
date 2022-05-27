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
     * @param m int整型
     * @param n int整型
     * @return ListNode类
     */
    ListNode *ReverseList(ListNode *pHead) {
        if (!pHead) return nullptr;
        ListNode *curr = pHead;
        ListNode *next = curr->next;
        while (next) {
            ListNode *tmp = next->next;
            pHead->next = next->next;
            next->next = curr;
            curr = next;
            next = tmp;
        }
        return curr;
    }

    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // write code here
        if (!head) return head;

        ListNode *dummyHead = new ListNode(-1);
        dummyHead->next = head;
        ListNode *begin = dummyHead;
        ListNode *end = dummyHead;

        for (int i = 1; i < m && begin; i++) begin = begin->next;
        for (int i = 0; i < n && end; i++) end = end->next;
        ListNode *start = begin->next;
        begin->next = nullptr;
        ListNode *tail = end->next;
        end->next = nullptr;
        begin->next = ReverseList(start);
        start->next = tail;
        return dummyHead->next;
    }
};