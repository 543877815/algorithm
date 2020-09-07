#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <stack>
#include <math.h>
#include <queue>
#include <assert.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *createLinkedList(int arr[], int n) {

    if (n == 0)
        return NULL;

    ListNode *head = new ListNode(arr[0]);
    ListNode *curNode = head;
    for (int i = 1; i < n; i++) {
        curNode->next = new ListNode(arr[i]);
        curNode = curNode->next;
    }

    return head;
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    vector<int> nums;

public:
    int pathSum(TreeNode *root, int sum) {
        int res = 0;
        if (root == nullptr) return res;
        nums.push_back(root->val);
        // 到达叶子结点
        if (root->left == nullptr && root->right == nullptr) {
            // 前缀和

        }
        if (root->left) {
            res += pathSum(root->left, sum);
            nums.pop_back();
        }
        if (root->right) {
            res += pathSum(root->right, sum);
            nums.pop_back();
        }
        return res;
    }
};

int main() {
    auto *solution = new Solution();
    TreeNode *five = new TreeNode(5);
    TreeNode *four = new TreeNode(4);
    TreeNode *eight = new TreeNode(8);
    TreeNode *eleven = new TreeNode(11);
    TreeNode *thirteen = new TreeNode(13);
    TreeNode *four_1 = new TreeNode(4);
    TreeNode *seven = new TreeNode(7);
    TreeNode *two = new TreeNode(2);
    TreeNode *five_1 = new TreeNode(5);
    TreeNode *one = new TreeNode(1);

    five->left = four;
    five->right = eight;
    four->left = eleven;
    eight->left = thirteen;
    eight->right = four_1;
    eleven->left = seven;
    eleven->right = two;
    four_1->left = five_1;
    four_1->right = one;

    TreeNode *test = new TreeNode(1);

    solution->pathSum(test, 0);
}
