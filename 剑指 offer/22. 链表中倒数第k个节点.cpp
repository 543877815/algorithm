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
    ListNode *getKthFromEnd(ListNode *head, int k) {
        int len = 0;
        ListNode *tmp = head;
        while (tmp) {
            len++;
            tmp = tmp->next;
        }
        while (len > k) {
            len--;
            head = head->next;
        }
        return head;
    }
};