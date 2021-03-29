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

// 遍历
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int left, int right) {
        if (left == right) return head;
        struct ListNode *preHead = new ListNode(0, head);
        struct ListNode *start = preHead;
        struct ListNode *curr = head;
        int i = 1;
        // 确定翻转的前一个结点
        while (curr && i < left) {
            start = start->next;
            curr = curr->next;
            i++;
        }
        // 确定翻转的后一个结点
        struct ListNode *end = NULL;
        while (curr && i < right) {
            curr = curr->next;
            end = curr->next;
            i++;
        }
        curr->next = NULL;
        // 进行翻转
        start->next = reverseList(start->next);
        while (start->next) {
            start = start->next;
        }
        start->next = end;
        return preHead->next;
    }

    ListNode *reverseList(ListNode *head) {
        struct ListNode *prev = NULL;
        struct ListNode *curr = head;
        struct ListNode *nextTemp = NULL;
        while (curr) {
            nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }
};