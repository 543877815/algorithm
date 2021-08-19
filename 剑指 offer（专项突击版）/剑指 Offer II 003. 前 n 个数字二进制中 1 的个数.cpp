// 遍历
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res = {0};
        int index = 1;
        while (index <= n) {
            int m = res.size();
            for (int i = 0; i < m && res.size() <= n; i++) {
                res.push_back(res[i] + 1);
            }
            index *= 2;
        }

        return res;
    }
};

// 动态规划
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> dp((num+1), 0);
        for (int i = 1; i <= num; i++) {
            dp[i] = dp[i >> 1] + (i & 1);
        }
        return dp;
    }
};