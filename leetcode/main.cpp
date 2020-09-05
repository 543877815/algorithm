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

class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (!root) return NULL;
        TreeNode *left = inorderSuccessor(root->left, p);
        if (left) return left;
        if (root->val > p->val) return root;
        TreeNode *right = inorderSuccessor(root->right, p);
        if (right) return right;
        return NULL;
    }
};


int main() {
    auto *solution = new Solution();
    TreeNode *five = new TreeNode(5);
    TreeNode *three = new TreeNode(3);
    TreeNode *two = new TreeNode(2);
    TreeNode *one = new TreeNode(1);
    five->left = three;
    three->left = two;
    two->left = one;
    TreeNode *p = new TreeNode(1);
    solution->inorderSuccessor(five, p);
}
