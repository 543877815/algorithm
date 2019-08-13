/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeElements(struct ListNode* head, int val){

    while(head) {
        if(head->val == val) {
            head = head->next;
        } else {
            break;
        }
    }
    if (head == NULL) return head;
    
    struct ListNode* root = head;
    struct ListNode* rootNext = root->next;
    
    while(root!=NULL && rootNext!=NULL) {
        if (rootNext->val == val){
            root->next = rootNext->next;
        } else {
            root = root->next;
        }
        if (root != NULL) rootNext = root->next;
    }
    return head;
}

