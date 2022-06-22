// 动态规划
// 时间复杂度：O(n^2)
// 空间复杂度：O(n)
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 给定数组的最长严格上升子序列的长度。
     * @param arr int整型vector 给定的数组
     * @return int整型
     */
    int LIS(vector<int>& arr) {
        // write code here
        int n = arr.size();
        if (n == 0) return 0;
        vector<int> dp(n, 1);
        for (int i = 1; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (arr[i] > arr[j]) {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
        }

        int res = 1;
        for (int i = 0; i < n; i++) {
            res = max(res, dp[i]);
        }
        return res;
    }
};