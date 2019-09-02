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

struct ListNode* reverseKGroup(struct ListNode* head, int k){
    if(!head || !head->next) return head;
    struct ListNode *prev = NULL;
    struct ListNode *curr = head;
    struct ListNode *tempHead = head;
    struct ListNode *tail = tempHead;
    struct ListNode *nextTemp = NULL;
    struct ListNode *returnHead = NULL;
    int count = 0;
    while(curr) {
        nextTemp = curr->next;
        curr->next = prev;
        prev = curr;  
        count++;
        if(count == k) {
            prev = NULL;
            if (returnHead == NULL) {
                tempHead = nextTemp;
                returnHead = curr;
            } else {
                tail->next = curr; // 下一段的头
                tail = tempHead;
                tempHead = nextTemp;
            }
            count = 0;
        }
        curr = nextTemp;
    }

    if (count != 0) {
        if (returnHead == NULL) return reverseList(prev);
        tail -> next = reverseList(prev);
    }
    
    return returnHead;
}

