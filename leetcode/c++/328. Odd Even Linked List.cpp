
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


// reference: 86
// 空间复杂度：O(1)
// 时间复杂度：O(n)
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return head;
        ListNode* large_head = NULL, *large_curr = NULL;
        ListNode* small_head = NULL, *small_curr = NULL;
        int index = 0;
        while(head) {
            if (index % 2 == 0) {
                if (!small_head) {
                    small_head = head;
                    small_curr = small_head;
                } else {
                    small_curr->next = head;
                    small_curr = small_curr->next;
                }
            } else {
                if (!large_head) {
                    large_head = head;
                    large_curr = large_head;
                } else {
                    large_curr->next = head;
                    large_curr = large_curr->next;
                }
            }
            index ++;
            head = head->next;
        }
        if (small_head) {
            head = small_head;
            small_curr -> next = large_head;
        } else if(large_head){
            head = large_head;
        }
        if (large_curr) large_curr -> next = NULL;

        return head;
    }
};