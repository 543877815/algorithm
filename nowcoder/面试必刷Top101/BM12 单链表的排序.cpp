/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */
// 复杂度：O(nlogn)
class Solution {
public:
    /**
     *
     * @param head ListNode类 the head node
     * @return ListNode类
     */

    ListNode* sortInList(ListNode* head, ListNode* tail) {
        if (!head) return nullptr;
        if (head->next == tail) {
            head->next = nullptr;
            return head;
        }

        ListNode* slow = head, *fast = head;
        while (fast != tail) {
            slow = slow->next;
            fast = fast->next;
            if (fast != tail) fast = fast->next;
        }

        ListNode* mid = slow;
        return merge(sortInList(head, mid), sortInList(mid, tail));
    }

    ListNode*
    merge(ListNode* head1, ListNode* head2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* tmp = dummyHead, *tmp1 = head1, *tmp2 = head2;
        while (tmp1 && tmp2) {
            if (tmp1->val < tmp2->val) {
                tmp->next = tmp1;
                tmp1 = tmp1->next;
            } else {
                tmp->next = tmp2;
                tmp2 = tmp2->next;
            }
            tmp = tmp->next;
        }

        if (tmp1) {
            tmp->next = tmp1;
        }
        if (tmp2) {
            tmp->next = tmp2;
        }
        return dummyHead->next;
    }

    ListNode* sortInList(ListNode* head) {
        // write code here
        return sortInList(head, nullptr);
    }
};