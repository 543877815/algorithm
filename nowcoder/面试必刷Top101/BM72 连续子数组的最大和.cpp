// 动态规划+前缀和
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int n = array.size();
        if (n == 0) return 0;
        if (n == 1) return array[0];
        vector<int> dp(n, 0);
        int min_sum = INT_MAX;
        int res = INT_MIN;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            min_sum = min(min_sum, sum);
            sum += array[i];
            res = max(res, sum);
            res = max(sum - min_sum, res);
        }
        return res;
    }
};