// 动态规划
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    int minCostClimbingStairs(vector<int> &cost) {
        int n = cost.size();
        vector<int> dp(n, 0);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < n; i++) {
            dp[i] = min(dp[i - 2] + cost[i], dp[i - 1] + cost[i]);
        }
        return min(dp[n - 1], dp[n - 2]);
    }
};


// 动态规划
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    int minCostClimbingStairs(vector<int> &cost) {
        int n = cost.size();
        int even = cost[0];
        int odd = cost[1];
        for (int i = 2; i < n; i++) {
            if (i % 2 == 0) even = min(even + cost[i], odd + cost[i]);
            else odd = min(even + cost[i], odd + cost[i]);
        }
        return min(even, odd);
    }
};