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

