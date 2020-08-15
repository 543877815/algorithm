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
    bool verify(vector<int> &postorder, int start, int end) {
        if (postorder.empty() || start == end) return true;
        if (end - start < 0) return false;

        int root = postorder[end];

        // 二叉搜索树中左子树节点的值小于根节点的值
        int i = start;
        for (; i <= end; i++) {
            if (postorder[i] > root) break;
        }

        // // 二叉搜索树中右子树节点的值大于根节点的值
        int j = i;
        for (; j < end; j++) {
            if (postorder[j] < root) return false;
        }

        if (j != end - 1) return false;

        // // 判断左子树是不是二叉搜索树
        bool left = true;
        if (i != j && i > 0) left = verify(postorder, start, i - 1);

        bool right = true;
        if (i != j) right = verify(postorder, i, end - 1);

        return left && right;
    }

    bool verifyPostorder(vector<int> &postorder) {
        int n = postorder.size();
        return verify(postorder, 0, n - 1);
    }
};
int main() {
    Solution solution = Solution();
    vector<int> postorder = {1,3,2,6,5};
    solution.verifyPostorder(postorder);
}
