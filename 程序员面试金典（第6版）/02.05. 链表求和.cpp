// 时间复杂度：O(n+m)
// 空间复杂度：O(n+m)
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *res = l1;
        ListNode *pre = NULL;
        int count = 0;
        while (l1 && l2) {
            int sum = l1->val + l2->val + count;
            count = sum / 10;
            l1->val = sum % 10;
            if (!l1->next) pre = l1;
            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1) {
            int sum = l1->val + count;
            count = sum / 10;
            l1->val = sum % 10;
            if (!l1->next) pre = l1;
            l1 = l1->next;
        }

        while (l2) {
            int sum = l2->val + count;
            count = sum / 10;
            pre->next = new ListNode(sum % 10);
            pre = pre->next;
            l2 = l2->next;
        }

        if (count != 0) pre->next = new ListNode(count);

        return res;
    }
};