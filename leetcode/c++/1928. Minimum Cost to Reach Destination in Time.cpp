// 动态规划
// 时间复杂度：O(tn)
// 空间复杂度：O(tn)
class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n = passingFees.size();
        const int MAX = INT_MAX / 2;

        // dp[t][i] 表示第t分钟到达城市i的最小花费
        vector<vector<int>> dp = vector<vector<int>>(maxTime+1, vector<int>(n, MAX));
        dp[0][0] = passingFees[0];
        int res = dp[maxTime][n-1];
        for (int t = 0; t <= maxTime; t++) {
            for (int i = 0; i < edges.size(); i++) {
                int start = edges[i][0];
                int end = edges[i][1];
                int time = edges[i][2];
                if (t+time <= maxTime) {
                    dp[t+time][end] = min(dp[t+time][end], dp[t][start] + passingFees[end]);
                    dp[t+time][start] = min(dp[t+time][start], dp[t][end] + passingFees[start]);
                }
            }
            res = min(res, dp[t][n-1]);
        }
        return res == MAX ? -1 : res;
    }
};

int main() {
    auto *solution = new Solution();
    TreeNode *five1 = new TreeNode(5);
    TreeNode *eight = new TreeNode(8);
    TreeNode *five2 = new TreeNode(5);

    vector<int> a = {1, 2, 3, 4, 5};
    vector<vector<int>> edges = {
            {0, 1, 10},
            {1, 2, 10},
            {2, 5, 10},
            {0, 3, 1},
            {3, 4, 10},
            {4, 5, 15}
    };
    vector<int> passingFees = {5, 1, 2, 20, 20, 3};
    solution->minCost(30, edges, passingFees);
}
