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

// 遍历
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode* curr = head;
        while (curr) {
            len++;
            curr = curr->next;
        }
        ListNode* pre = new ListNode();
        pre->next = head;
        curr = head;
        int index = 0;
        while (index < len - n) {
            pre = pre->next;
            curr = curr->next;
            index++;
        }
        pre->next = curr->next;
        if (curr == head) return curr->next;

        return head;
    }
};