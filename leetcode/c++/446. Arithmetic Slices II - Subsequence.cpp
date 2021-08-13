// 动态规划 + f[i][d] 表示尾项为 nums[i]，差值为 d 的等差数列
// 时间复杂度：O(n^2)
// 空间复杂度：O(n^2)

class Solution {
public:
    int numberOfArithmeticSlices(vector<int> &nums) {
        int n = nums.size();
        int res = 0;
        vector <unordered_map<long long, int>> f(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                long long d = 1LL * nums[i] - nums[j];
                auto it = f[j].find(d);
                int cnt = it == f[j].end() ? 0 : it->second;
                res += cnt;
                f[i][d] += cnt + 1;
            }
        }
        return res;
    }
};