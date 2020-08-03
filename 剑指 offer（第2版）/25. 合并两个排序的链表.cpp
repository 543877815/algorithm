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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode * root = NULL, *p = NULL;
        while(l1 && l2) {
            if (root == NULL) {
                root = new ListNode();
                p = root;
                if (l1->val < l2->val) {
                    root->val = l1->val;
                    l1 = l1->next;
                } else {
                    root->val = l2->val;
                    l2 = l2->next;
                }
            } else {
                ListNode * node = new ListNode();
                if (l1->val < l2->val) {
                    node->val = l1->val;
                    l1 = l1->next;
                } else {
                    node->val = l2->val;
                    l2 = l2->next;
                }
                p->next = node;
                p = p->next;
            }
        }
        while(l1) {
            if (root == NULL) {
                root = new ListNode();
                p = root;
                root->val = l1->val;
            } else {
                ListNode * node = new ListNode();
                node->val = l1->val;
                p->next = node;
                p = p->next;
            }
            l1 = l1->next;
        }
        while(l2) {
            if (root == NULL) {
                root = new ListNode();
                p = root;
                root->val = l2->val;
            } else {
                ListNode * node = new ListNode();
                node->val = l2->val;
                p->next = node;
                p = p->next;
            }
            l2 = l2->next;
        }
        return root;
    }
};