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

// c++ 2021/06/06
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *dummyHead = new ListNode();
        dummyHead->next = head;
        ListNode *curr = dummyHead;
        while (curr && curr->next) {
            if (curr->next->val == val) {
                ListNode *tmp = curr->next;
                curr->next = curr->next->next;
            } else curr = curr->next;
        }

        return dummyHead->next;
    }
};