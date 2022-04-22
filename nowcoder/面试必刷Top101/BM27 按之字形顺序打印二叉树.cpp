/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
// 队列
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int>> res;
        queue<TreeNode *> sk;
        if (!pRoot) return res;
        sk.push(pRoot);
        int level = 0;
        while (!sk.empty()) {
            int n = sk.size();
            vector<int> tmp;
            for (int i = 0; i < n; i++) {
                TreeNode* curr = sk.front();
                sk.pop();
                tmp.push_back(curr->val);
                if (curr->left) sk.push(curr->left);
                if (curr->right) sk.push(curr->right);
            }
            if (level % 2 == 1) reverse(tmp.begin(), tmp.end());
            res.push_back(tmp);
            level++;
        }
        return res;
    }

};