/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
    struct ListNode *prev = NULL;
    struct ListNode *curr = head;
    struct ListNode *nextTemp = NULL;
    while(curr) {
        nextTemp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTemp;
    }
    return prev;
}

// 空间复杂度：O(1)
// 时间复杂度：O(n)
bool isPalindrome(struct ListNode* head){
    if (!head || !head->next) return true;
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next;
        if(fast) fast = fast->next;
    }
    struct ListNode * reversehead = reverseList(slow);
    while(head && reversehead) {
        if(head->val!=reversehead->val){
            return false;
        }
        head = head -> next;
        reversehead = reversehead -> next;
    }
    return true;
}

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