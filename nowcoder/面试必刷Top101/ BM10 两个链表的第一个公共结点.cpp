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
    ListNode *FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2) {
        int n = 0;
        int m = 0;
        ListNode *curr = pHead1;
        while (curr) {
            curr = curr->next;
            n++;
        }
        curr = pHead2;
        while (curr) {
            curr = curr->next;
            m++;
        }

        int diff = abs(m - n);
        if (m > n) {
            curr = pHead2;
            for (int i = 0; i < m - n; i++) {
                curr = curr->next;
            }
            ListNode *curr1 = pHead1;
            while (curr && curr1 && curr != curr1) {
                curr = curr->next;
                curr1 = curr1->next;
            }
        } else {
            curr = pHead1;
            for (int i = 0; i < n - m; i++) {
                curr = curr->next;
            }
            ListNode *curr1 = pHead2;
            while (curr && curr1 && curr != curr1) {
                curr = curr->next;
                curr1 = curr1->next;
            }
        }

        return curr;
    }
};