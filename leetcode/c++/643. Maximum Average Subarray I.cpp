// 滑动窗口
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    double max(double a, double b) {
        return a > b ? a : b;
    }

    double findMaxAverage(vector<int> &nums, int k) {
        double sum = 0;
        int n = nums.size();
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }
        double res = sum / k;
        int left = 0, right = k;
        while (right < n && left < n) {
            sum += nums[right++];
            sum -= nums[left++];
            res = max(res, sum / k);
        }

        return res;
    }
};