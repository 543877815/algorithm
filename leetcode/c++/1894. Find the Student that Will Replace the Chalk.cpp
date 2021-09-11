// 前缀和
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    int chalkReplacer(vector<int> &chalk, int k) {
        int n = chalk.size();
        vector<long> presum = vector<long>(n + 1, 0);
        for (int i = 0; i < n; i++) {
            presum[i + 1] = presum[i] + chalk[i];
        }
        k -= k / presum[n] * presum[n];
        for (int i = n; i >= 0; i--) {
            if (presum[i] <= k) return i == n ? 0 : i;
        }

        return 0;
    }
};

// 前缀和+二分搜索
class Solution {
public:
    int chalkReplacer(vector<int> &chalk, int k) {
        int n = chalk.size();
        if (chalk[0] > k) return 0;
        for (int i = 1; i < n; i++) {
            chalk[i] += chalk[i - 1];
            if (chalk[i] > k) return i;
        }

        k %= chalk.back();
        return upper_bound(chalk.begin(), chalk.end(), k) - chalk.begin();
    }
};