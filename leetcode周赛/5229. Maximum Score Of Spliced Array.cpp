// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    int getMaxSum(vector<int> &diff) {
        int res = 0;
        int tmp = 0;
        int n = diff.size();
        for (int i = 0; i < n; i++) {
            tmp += diff[i];
            res = max(res, tmp);
            if (tmp < 0) tmp = 0;
        }

        return res;
    }

    int maximumsSplicedArray(vector<int> &nums1, vector<int> &nums2) {
        int n = nums1.size();
        vector<int> diff1(n, 0);
        vector<int> diff2(n, 0);
        int sum1 = 0, sum2 = 0;
        for (int i = 0; i < n; i++) {
            sum1 += nums1[i];
            sum2 += nums2[i];
            diff1[i] = nums1[i] - nums2[i];
            diff2[i] = nums2[i] - nums1[i];
        }

        int res = max(sum1, sum2);
        res = max(res, sum1 + getMaxSum(diff2));
        res = max(res, sum2 + getMaxSum(diff1));

        return res;

    }
};