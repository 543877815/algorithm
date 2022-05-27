// struct TreeNode{
//     int val;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode(): val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) {}
// };

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 求二叉树的右视图
     * @param xianxu int整型vector 先序遍历
     * @param zhongxu int整型vector 中序遍历
     * @return int整型vector
     */

    unordered_map<int, int> index;

    TreeNode* build(vector<int> &preorder, int s1, int e1, vector<int> &inorder, int s2, int e2) {
        if (s1 > e1 || s2 > e2) return nullptr;
        int n = preorder.size();
        TreeNode *root = new TreeNode(preorder[s1]);
        int rootIdx = index[preorder[s1]];
        int left_subtree = rootIdx - s2;
        root->left = build(preorder, s1+1, s1+left_subtree, inorder, s2, rootIdx-1);
        root->right = build(preorder, s1+left_subtree+1, e1, inorder, rootIdx+1, e2);
        return root;
    }

    vector<int> solve(vector<int>& xianxu, vector<int>& zhongxu) {
        // write code here
        int n = zhongxu.size();
        for (int i = 0; i < n; i++) {
            index[zhongxu[i]] = i;
        }
        TreeNode* root = build(xianxu, 0, n-1, zhongxu, 0, n-1);
        queue<TreeNode*> q;
        q.push(root);
        vector<int> res;
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode* curr = q.front();
                if (i == n - 1) res.push_back(curr->val);
                q.pop();
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
        }
        return res;
    }
};