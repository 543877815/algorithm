// 动态规划
// 时间复杂度：O(nxaim)
// 空间复杂度：O(aim)
class Solution {
public:
    /**
     * 最少货币数
     * @param arr int整型vector the array
     * @param aim int整型 the target
     * @return int整型
     */
    int minMoney(vector<int>& arr, int aim) {
        // write code here
        int n = arr.size();
        if (aim == 0) return 0;
        vector<int> dp(aim+1, aim+1);
        dp[0] = 0;
        for (int i = 0; i <= aim; i++) {
            for (int j = 0;  j < n; j++) {
                if (i + arr[j] <= aim) {
                    dp[i+arr[j]] = min(dp[i+arr[j]], dp[i] + 1);
                }
            }
        }

        return (dp[aim] == aim + 1) ? -1 : dp[aim];
    }
};