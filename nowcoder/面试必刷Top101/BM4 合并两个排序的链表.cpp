/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/

// 时间复杂度：O(n+m)
// 空间复杂度：O(1)
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        ListNode* dummyHead = new ListNode(-1);
        ListNode* curr = dummyHead;
        while (pHead1 && pHead2) {
            if (pHead1->val < pHead2->val) {
                curr->next = pHead1;
                pHead1 = pHead1->next;
            } else {
                curr->next = pHead2;
                pHead2 = pHead2->next;
            }
            curr = curr->next;
        }
        if (pHead1) curr->next = pHead1;
        if (pHead2) curr->next = pHead2;
        return dummyHead->next;
    }
};