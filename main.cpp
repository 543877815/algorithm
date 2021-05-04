
#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <stack>
#include <queue>
#include <cstring>
#include <numeric>
#include <math.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    bool deleteNode(TreeNode* root) {
        if (!root) return true;
        if (root->left && deleteNode(root->left))
            root->left = nullptr;
        if (root->right && deleteNode(root->right))
            root->right = nullptr;
        if (root->val == 0 && !root->left && !root->right)
            return true;
        return false;
    }

    TreeNode* pruneTree(TreeNode* root) {
        if (!root) return root;
        else deleteNode(root);
        return root;
    }
};

int main() {
    auto *solution = new Solution();
    TreeNode* one = new TreeNode(1);
    TreeNode* two = new TreeNode(0);
    TreeNode* three = new TreeNode(0);
    TreeNode* four = new TreeNode(1);
    one->right = two;
    two->left = three;
    two->right = four;

    solution->pruneTree(one);

}


