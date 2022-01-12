// 双向遍历
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    bool increasingTriplet(vector<int> &nums) {
        int n = nums.size();
        if (n < 3) return false;
        vector<int> left(n, INT_MAX);
        vector<int> right(n, INT_MIN);
        int left_min = nums[0];
        for (int i = 1; i < n; i++) {
            left[i] = left_min;
            left_min = min(left_min, nums[i]);
        }

        int right_max = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            right[i] = right_max;
            right_max = max(right_max, nums[i]);
        }

        for (int i = 1; i < n - 1; i++) {
            if (nums[i] < right[i] && nums[i] > left[i]) return true;
        }

        return false;
    }
};

// 贪心
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    bool increasingTriplet(vector<int> &nums) {
        int n = nums.size();
        int first = nums[0], second = INT_MAX;
        for (int i = 1; i < n; i++) {
            if (nums[i] > second) return true;
            else if (nums[i] > first) second = nums[i];
            else first = nums[i];
        }

        return false;
    }
};