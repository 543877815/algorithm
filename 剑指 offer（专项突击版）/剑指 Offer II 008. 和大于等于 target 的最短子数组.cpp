// 队列
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    int minSubArrayLen(int target, vector<int> &nums) {
        int n = nums.size();
        queue<int> q;
        int res = INT_MAX;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            q.push(nums[i]);
            while (sum >= target && !q.empty()) {
                res = min(res, (int) q.size());
                sum -= q.front();
                q.pop();
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};

// 双索引法
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    int minSubArrayLen(int target, vector<int> &nums) {
        int n = nums.size();
        int left = 0, right = 0;
        int sum = 0;
        int res = INT_MAX;
        while (left <= right && right < n) {
            sum += nums[right];
            while (left <= right && right < n && sum >= target) {
                res = min(res, right - left + 1);
                sum -= nums[left++];
            }
            right++;
        }
        return res == INT_MAX ? 0 : res;
    }
};

// 前缀和
// 时间复杂度：O(nlogn)
// 空间复杂度：O(n)
class Solution {
public:
    int minSubArrayLen(int target, vector<int> &nums) {
        int n = nums.size();
        vector<int> presum = vector<int>(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            presum[i] = presum[i - 1] + nums[i - 1];
        }

        int res = INT_MAX;

        for (int i = 1; i <= n; i++) {
            int s = target + presum[i - 1];
            auto bound = lower_bound(presum.begin(), presum.end(), s);
            if (bound != presum.end()) {
                res = min(res, static_cast<int>(bound - presum.begin() - (i - 1)));
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};