// 动态规划
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n, 0);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < n; i++) {
            dp[i] = min(dp[i-1], dp[i-2]) + cost[i];
        }

        return min(dp[n-1], dp[n-2]);
    }
};

// 状态压缩
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n, 0);
        int zero = cost[0];
        int one = cost[1];
        int two = 0;
        for (int i = 2; i < n; i++) {
            two = min(zero, one) + cost[i];
            zero = one;
            one = two;
        }

        return min(zero, one);
    }
};