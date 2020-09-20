// 使用__builtin_popcount
// 时间复杂度：O(n*sizeof(Interger))
// 空间复杂度：O(n)
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res;
        for (int i = 0; i <= num; i++) {
            res.push_back(__builtin_popcount(i));
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
        vector<int> dp((num + 1), 0);
        for (int i = 1; i <= num; i++) {
            dp[i] = dp[i >> 1] + (i & 1);
        }
        return dp;
    }
};
