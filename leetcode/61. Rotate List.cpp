/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* rotateRight(struct ListNode* head, int k){
    if (!head || !head -> next || k == 0) return head; 
    int length = 1;
    struct ListNode *tail = head;
    while(tail->next) {
        length++;
        tail = tail -> next;
    }
    tail->next = head; // 成环
    
    int dis = length - k % length;
    struct ListNode* newtail = head;
    while (dis != 1) {
        newtail = newtail -> next;
        dis--;
    }
    head = newtail->next;
    newtail->next = NULL;
    return head;
}

// 先成环，再破环
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k == 0) return head;
        int length = 1;
        ListNode *tail = head;
        while(tail->next) {
            length++;
            tail = tail->next;
        }
        tail -> next = head; // 成环
        int dis = length - k % length;
        ListNode * newTail = head;
        while(dis != 1) {
            newTail = newTail->next;
            dis--;
        }
        head = newTail->next;
        newTail->next = NULL;
        return head;
    }
};