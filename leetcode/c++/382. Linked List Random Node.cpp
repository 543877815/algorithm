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
 // 水塘抽样（Reservoir Sampling）
 // 时间复杂度：O(n)
 // 空间复杂度：O(1)
class Solution {
public:
    ListNode* head;
    Solution(ListNode* head) {
        this->head = head;
    }

    int getRandom() {
        int len = 0;
        while (head) {
            len++;
            int possibility = rand() % len;
            if (possibility < 1) return head->val;
            head = head->next;
        }
        return getRandom();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */