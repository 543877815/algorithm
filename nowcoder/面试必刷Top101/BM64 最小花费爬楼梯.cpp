// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param cost int整型vector
     * @return int整型
     */
    int minCostClimbingStairs(vector<int> &cost) {
        // write code here
        int n = cost.size();
        if (n <= 2) return 0;
        vector<int> dp(n + 1, 0);
        for (int i = 2; i <= n; i++) {
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }

        return dp[n];
    }
};

// 状态压缩
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param cost int整型vector
     * @return int整型
     */
    int minCostClimbingStairs(vector<int> &cost) {
        // write code here
        int n = cost.size();
        int a = 0, b = 0, c;
        if (n <= 2) return 0;
//         vector<int> dp(n + 1, 0);
        for (int i = 2; i <= n; i++) {
            c = min(a + cost[i - 1], b + cost[i - 2]);
            b = a;
            a = c;
//             dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]);
        }

        return c;
    }
};