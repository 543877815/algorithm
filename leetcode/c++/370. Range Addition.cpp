// 差分动态规划
// 时间复杂度：O(m)
// 空间复杂度：O(n)
class Solution {
public:
    vector<int> getModifiedArray(int length, vector <vector<int>> &updates) {
        vector<int> res(length, 0);
        vector<int> dp(length + 1, 0);
        int n = updates.size();
        for (int i = 0; i < n; i++) {
            int left = updates[i][0], right = updates[i][1], num = updates[i][2];
            dp[left] += num;
            dp[right + 1] -= num;
        }

        for (int i = 1; i <= length; i++) {
            dp[i] += dp[i - 1];
        }

        for (int i = 0; i < length; i++) {
            res[i] += dp[i];
        }

        return res;
    }
};