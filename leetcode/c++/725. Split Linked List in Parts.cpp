// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    vector<ListNode *> splitListToParts(ListNode *head, int k) {
        int len = 0;
        ListNode *curr = head;
        ListNode *pre = new ListNode();
        pre->next = head;
        while (curr) {
            len++;
            curr = curr->next;
        }

        vector < ListNode * > res;
        curr = head;
        while (k > 0) {
            int remain = len % k;
            int count = len / k + (remain == 0 ? 0 : 1);
            len -= count;
            k--;
            while (count > 0) {
                pre = pre->next;
                count--;
            }
            res.push_back(curr);
            curr = pre->next;
            pre->next = nullptr;
            pre = new ListNode(0, curr);
        }
        return res;
    }
};