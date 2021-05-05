
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


<<<<<<< HEAD
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    TreeNode* pre;
    TreeNode* head;
    void inOrderTraverse(TreeNode* root) {
        if (!root) return;
        if (root->left) inOrderTraverse(root->left);
        root->left = NULL;
        if (!head) {
            head = root;
            pre = root;
        } else {
            pre->right = root;
            pre = root;
        }
        if (root->right) inOrderTraverse(root->right);
    }

    TreeNode* increasingBST(TreeNode* root) {
        inOrderTraverse(root);
        return head;
    }
};
int main() {
    TreeNode *one = new TreeNode(1);
    TreeNode *two = new TreeNode(2);
    TreeNode *three = new TreeNode(3);
    TreeNode *four = new TreeNode(4);
    TreeNode *five = new TreeNode(5);
    TreeNode *six = new TreeNode(6);
    TreeNode *seven = new TreeNode(7);
    TreeNode *eight = new TreeNode(8);
    TreeNode *nine = new TreeNode(9);

    two->left = one;
    three->left = two;
    three->right = four;
    five->left = three;
    five->right = six;
    six->right = eight;
    eight->left = seven;
    eight->right = nine;

    auto *solution = new Solution();
    solution->increasingBST(five);

}

=======
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


>>>>>>> b801056e9539e613ca67d58ab749c4bb5ac53cfb
