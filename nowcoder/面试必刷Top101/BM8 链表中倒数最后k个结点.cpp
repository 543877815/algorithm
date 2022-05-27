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
     * @param pHead ListNode类
     * @param k int整型
     * @return ListNode类
     */
    ListNode *FindKthToTail(ListNode *pHead, int k) {
        // write code here
        int n = 0;
        ListNode *curr = pHead;
        while (curr) {
            curr = curr->next;
            n++;
        }
        if (k > n) return nullptr;
        n = n - k;
        curr = pHead;
        while (n > 0) {
            curr = curr->next;
            n--;
        }
        return curr;
    }
};