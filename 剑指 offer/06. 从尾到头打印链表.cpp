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
    vector<int> reversePrint(ListNode* head) {
        stack<int> record;
        vector<int> res;
        while(head) {
            record.push(head->val);
            head = head->next;
        }
        while(!record.empty()) {
            res.push_back(record.top());
            record.pop();
        }
        return res;
    }
};