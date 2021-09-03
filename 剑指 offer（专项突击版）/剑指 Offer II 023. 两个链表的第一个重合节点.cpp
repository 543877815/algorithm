/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 遍历
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1 = 0, len2 = 0;
        ListNode *currA = headA;
        ListNode *currB = headB;
        while (currA) {
            currA = currA->next;
            len1++;
        }

        while (currB) {
            currB = currB->next;
            len2++;
        }

        int dis = abs(len1 - len2);
        ListNode *fast = NULL;
        ListNode *slow = NULL;
        if (len1 > len2) {
            fast = headA;
            slow = headB;
        } else {
            fast = headB;
            slow = headA;
        }

        while (dis > 0) {
            fast = fast->next;
            dis--;
        }

        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }

        return fast;
    }
};