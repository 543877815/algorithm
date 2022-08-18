// 快速排序
// 时间复杂度：O(nlogn)
// 空间复杂度：O(logn)
class Solution {
public:
    int maximumGap(vector<int> &nums) {
        int m = nums.size();
        if (m < 2) return 0;
        sort(nums.begin(), nums.end());
        int max_num = INT_MIN;
        for (int i = 0; i < m - 1; i++) {
            if (nums[i + 1] - nums[i] > max_num) {
                max_num = nums[i + 1] - nums[i];
            }
        }

        return max_num;
    }
};


// 基数排序
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    int maximumGap(vector<int> &nums) {
        int n = nums.size();
        int exp = 1;
        int max_value = *max_element(nums.begin(), nums.end());
        vector<int> tmp(n);

        while (exp <= max_value) {
            vector<int> cnt(10);
            for (int i = 0; i < n; i++) {
                int digit = (nums[i] / exp) % 10;
                cnt[digit]++;
            }
            for (int i = 1; i < 10; i++) {
                cnt[i] += cnt[i - 1];
            }
            for (int i = n - 1; i >= 0; i--) {
                int digit = (nums[i] / exp) % 10;
                tmp[cnt[digit] - 1] = nums[i];
                cnt[digit]--;
            }
            exp *= 10;
            copy(tmp.begin(), tmp.end(), nums.begin());
        }

        int res = 0;
        for (int i = 1; i < n; i++) {
            res = max(nums[i] - nums[i - 1], res);
        }

        return res;
    }
};