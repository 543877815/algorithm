/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    ListNode *ReverseList(ListNode *pHead) {
        if (!pHead) return nullptr;
        ListNode *curr = pHead;
        ListNode *next = curr->next;
        while (next) {
            ListNode *tmp = next->next;
            pHead->next = next->next;
            next->next = curr;
            curr = next;
            next = tmp;
        }
        return curr;
    }
};