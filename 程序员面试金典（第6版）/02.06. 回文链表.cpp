/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 快慢指针，翻转链表
class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *nextTemp = NULL;
        while (curr) {
            nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }


    bool isPalindrome(ListNode *head) {
        if (!head || !head->next) return true;
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next;
            if (fast) fast = fast->next;
        }
        ListNode *reversehead = reverseList(slow);
        while (head && reversehead) {
            if (head->val != reversehead->val) {
                return false;
            }
            head = head->next;
            reversehead = reversehead->next;
        }
        return true;
    }
};