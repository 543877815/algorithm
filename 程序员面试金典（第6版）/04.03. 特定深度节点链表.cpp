/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 时间复杂度：O(n)
// 空间复杂度：O(2^h)
class Solution {
public:
    vector<ListNode *> listOfDepth(TreeNode *tree) {
        vector < ListNode * > res;
        queue <pair<int, TreeNode *>> q;
        if (!tree) return res;
        ListNode *head = NULL;
        ListNode *node = head;
        int currLevel = -1;
        q.push(make_pair(0, tree));
        while (!q.empty()) {
            int level = q.front().first;
            TreeNode *curr = q.front().second;
            q.pop();
            if (level != currLevel) {
                currLevel = level;
                if (head != NULL) res.push_back(head);
                head = new ListNode(curr->val);
                node = head;
            } else {
                node->next = new ListNode(curr->val);
                node = node->next;
            }
            if (curr->left) q.push(make_pair(level + 1, curr->left));
            if (curr->right) q.push(make_pair(level + 1, curr->right));
        }
        res.push_back(head);
        return res;
    }
};