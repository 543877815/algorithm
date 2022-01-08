// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        string s1;
        string s2;
        while (l1) {
            s1.push_back(l1->val + '0');
            l1 = l1->next;
        }
        while (l2) {
            s2.push_back(l2->val + '0');
            l2 = l2->next;
        }
        int n1 = s1.size() - 1;
        int n2 = s2.size() - 1;
        int digit = 0;
        string s;
        while (n1 >= 0 && n2 >= 0) {
            int val = digit + (s1[n1] - '0') + (s2[n2] - '0');
            s.push_back(val % 10 + '0');
            digit = val / 10;
            n1--;
            n2--;
        }

        while (n1 >= 0) {
            int val = digit + (s1[n1] - '0');
            s.push_back(val % 10 + '0');
            digit = val / 10;
            n1--;
        }

        while (n2 >= 0) {
            int val = digit + (s2[n2] - '0');
            s.push_back(val % 10 + '0');
            digit = val / 10;
            n2--;
        }

        if (digit != 0) s.push_back(digit + '0');
        int n = s.size() - 1;
        ListNode *dummyHead = new ListNode(-1);
        ListNode *pre = dummyHead;
        while (n >= 0) {
            pre->next = new ListNode(s[n] - '0');
            pre = pre->next;
            n--;
        }

        return dummyHead->next;

    }
};