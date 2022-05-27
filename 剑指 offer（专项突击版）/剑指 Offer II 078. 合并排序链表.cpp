/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// 归并排序
// 时间复杂度：O(n^2logn)
// 空间复杂度：O(logn)
class Solution {
public:
    ListNode *merge(ListNode *head1, ListNode *head2) {
        ListNode *dummyHead = new ListNode(0);
        ListNode *curr = dummyHead;
        while (head1 && head2) {
            if (head1->val < head2->val) {
                curr->next = head1;
                head1 = head1->next;
            } else {
                curr->next = head2;
                head2 = head2->next;
            }
            curr = curr->next;
        }
        if (head1) {
            curr->next = head1;
        } else if (head2) {
            curr->next = head2;
        }
        return dummyHead->next;
    }

    ListNode *mergeKLists(vector<ListNode *> &lists) {
        int n = lists.size();
        ListNode *dummyHead = new ListNode(-10001);
        for (int i = 0; i < n; i++) {
            dummyHead = merge(dummyHead, lists[i]);
        }

        return dummyHead->next;
    }
};