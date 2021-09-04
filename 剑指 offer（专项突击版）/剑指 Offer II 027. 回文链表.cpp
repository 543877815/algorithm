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

// 链表翻转
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    struct ListNode *reverseList(struct ListNode *head) {
        struct ListNode *prev = NULL;
        struct ListNode *curr = head;
        struct ListNode *nextTemp = NULL;
        while (curr) {
            nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        ListNode* pre = new ListNode(-1);
        ListNode* slow = head;
        ListNode* fast = head;
        pre->next = slow;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            pre = pre->next;
        }
        pre->next = nullptr;
        ListNode* currHalf = reverseList(slow);
        ListNode* curr = head;
        while (curr && currHalf) {
            if (curr->val != currHalf->val) return false;
            curr = curr->next;
            currHalf = currHalf->next;
        }

        return true;

    }
};