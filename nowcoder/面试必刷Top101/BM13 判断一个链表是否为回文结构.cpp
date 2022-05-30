/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    /**
     *
     * @param head ListNode类 the head
     * @return bool布尔型
     */
    bool isPail(ListNode *head) {
        int length = 0;
        ListNode *curr = head;
        while (curr) {
            curr = curr->next;
            length++;
        }
        stack<int> sk;
        curr = head;
        int half_length = length / 2;
        while (half_length > 0) {
            sk.push(curr->val);
            curr = curr->next;
            half_length--;
        }
        if (length % 2 == 1) curr = curr->next;
        while (!sk.empty() && curr) {
            if (sk.top() != curr->val) return false;
            curr = curr->next;
            sk.pop();
        }

        return true;
    }
};