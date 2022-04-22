/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
// 层次遍历
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param root TreeNode类
     * @return bool布尔型
     */
    bool isCompleteTree(TreeNode *root) {
        queue < TreeNode * > q;
        if (!root) return true;
        q.push(root);
        int num = 1;
        bool maybeLast = false;
        while (!q.empty()) {
            int n = q.size();
            if (num != n) maybeLast = true;
            bool empty = false;
            for (int i = 0; i < n; i++) {
                TreeNode *curr = q.front();
                q.pop();
                if (maybeLast && (curr->left || curr->right)) return false;
                if (curr->left) {
                    if (empty) return false;
                    q.push(curr->left);
                } else empty = true;
                if (curr->right) {
                    if (empty) return false;
                    else q.push(curr->right);
                } else empty = true;
            }
            num *= 2;
        }
        return true;
    }
};