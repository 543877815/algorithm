/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 链表反转
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    /**
     *
     * @param head1 ListNode类
     * @param head2 ListNode类
     * @return ListNode类
     */
    ListNode *reverse(ListNode *pHead) {
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

    ListNode *addInList(ListNode *head1, ListNode *head2) {
        // write code here
        head1 = reverse(head1);
        head2 = reverse(head2);
        ListNode *dummyHead = new ListNode(-1);
        ListNode *curr = dummyHead;
        int digit = 0;
        while (head1 && head2) {
            int num = (head1->val + head2->val + digit);
            int val = num % 10;
            curr->next = new ListNode(val);
            curr = curr->next;
            digit = num / 10;
            head1 = head1->next;
            head2 = head2->next;
        }

        while (head1) {
            int num = (head1->val + digit);
            int val = num % 10;
            curr->next = new ListNode(val);
            curr = curr->next;
            digit = num / 10;
            head1 = head1->next;
        }

        while (head2) {
            int num = (head2->val + digit);
            int val = num % 10;
            curr->next = new ListNode(val);
            curr = curr->next;
            digit = num / 10;
            head2 = head2->next;
        }

        if (digit) {
            curr->next = new ListNode(digit);
            curr = curr->next;
        }

        ListNode *res = reverse(dummyHead->next);
        return res;
    }
};