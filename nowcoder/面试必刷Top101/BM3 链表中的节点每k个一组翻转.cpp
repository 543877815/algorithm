/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */
// 链表反转
// 时间复杂度：O(n^2)
// 空间复杂度：O(1)
class Solution {
public:
    /**
     *
     * @param head ListNode类
     * @param k int整型
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

    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode *pre = dummyHead;
        ListNode *tail = dummyHead;
        while (tail) {
            int tmp = k;
            while (tail && tmp > 0) {
                tmp--;
                tail = tail->next;
            }
            if (tail && tmp >= 0) {
                ListNode *next = tail->next;
                tail->next = nullptr;
                ListNode *list_Tail = pre->next;
                pre->next = ReverseList(pre->next);
                list_Tail->next = next;
                pre = list_Tail;
                tail = pre;
            } else break;
        }

        return dummyHead->next;
    }
};