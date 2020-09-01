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
    bool PredictTheWinner(vector<int> &nums) {
        int n = nums.size();
        if ((n & 1) == 0) return true;
        // dp[i][j]表示第i到第j中可以获得的最大分数
        vector<vector<int>> dp = vector<vector<int>>(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            dp[i][i] = nums[i];
        }
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (j - i == 1)
                    dp[i][j] = max(nums[i], nums[j]);
                else if (j - i > 1)
                    dp[i][j] = max(dp[i + 1][j] + nums[i], dp[i][j - 1] + nums[j]);
            }
        }
        return dp[0][n - 1] > dp[1][n - 1] && dp[0][n - 1] > dp[0][n - 2];
    }
};

int main() {
    Solution solution = Solution();
    vector<int> rooms = {1, 5, 2};
    solution.PredictTheWinner(rooms);
}
