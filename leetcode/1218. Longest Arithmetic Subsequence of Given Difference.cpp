// 动态规划
// 时间复杂度：O(n^2)
// 空间复杂度：O(n)
class Solution {
public:
    int longestSubsequence(vector<int> &arr, int difference) {
        int n = arr.size();
        if (n == 0) return 0;
        // dp[i]表示以第i个元素为结尾的最长定差子序列
        vector<int> dp(n, 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[i] - arr[j] == difference) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return dp[n - 1];
    }
};


// 动态规划 哈希表
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    int longestSubsequence(vector<int> &arr, int difference) {
        int res = 0;
        unordered_map<int, int> hash;
        for (auto i : arr) res = max(res, hash[i] = hash[i - difference] + 1);
        return res;
    }
};