/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/

// 快慢指针
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        ListNode* fast = pHead;
        ListNode* slow = pHead;
        while (fast) {
            slow = slow->next;
            fast = fast->next;
            if (fast) fast = fast->next;
            else return nullptr;
            if (fast == slow) break;
        }
        slow = pHead;
        while(slow && fast && slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        return fast;
    }
};