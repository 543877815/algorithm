/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param head ListNode类
     * @return ListNode类
     */
    ListNode *oddEvenList(ListNode *head) {
        // write code here
        ListNode *dummyHead1 = new ListNode(-1);
        ListNode *dummyHead2 = new ListNode(-1);
        ListNode *curr = head;
        ListNode *curr1 = dummyHead1;
        ListNode *curr2 = dummyHead2;

        int i = 1;
        while (curr) {
            if (i % 2 == 1) {
                curr1->next = curr;
                curr1 = curr1->next;
            } else {
                curr2->next = curr;
                curr2 = curr2->next;
            }
            curr = curr->next;
            i++;
        }

        curr1->next = dummyHead2->next;
        curr2->next = nullptr;
        return dummyHead1->next;

    }
};