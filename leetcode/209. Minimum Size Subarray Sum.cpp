// 双索引法
// 时间复杂度：O(n)
// 空间复杂度: O(1)
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int l = 0, r = 0;
        int sum = 0;
        int res = nums.size() + 1;
        while( l < nums.size()) {
            if (r < nums.size() && sum < s) {
                sum += nums[r++];
            } else {
                sum -= nums[l++];
            }

            if (sum >= s) {
                res = min(res, r-l);
            }
        }
        if (res == nums.size() +1) return 0;
        return res;
    }
};

// 前缀法
// 时间复杂度: O(nlogn)
// 空间复杂度：O(n)
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int size = nums.size();
        if (size == 0) return 0;
        int ans = size + 1;
        vector<int> sums(size+1, 0);
        // 为了方便计算，令 size = n + 1
        // sums[0] = 0 意味着前 0 个元素的前缀和为 0
        // sums[1] = A[0] 前 1 个元素的前缀和为 A[0]
        // 以此类推
        for (int i = 1; i <= size; i++) {
            sums[i] = sums[i-1] + nums[i-1];
        }

        for (int i = 1; i <= size; i++) {
            int target = s + sums[i - 1];
            auto bound = lower_bound(sums.begin(), sums.end(), target);
            if (bound != sums.end()) {
                ans = min(ans, static_cast<int>((bound - sums.begin()) - (i - 1)));
            }
        }
        return ans == size + 1 ? 0 : ans;
    }
};