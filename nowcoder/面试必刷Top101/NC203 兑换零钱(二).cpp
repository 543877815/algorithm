// 超时
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param target int整型
     * @param nums int整型vector
     * @return int整型
     */

    int res = 0;

    void search(int target, vector<int> &nums, int idx) {
        if (target == 0) {
            res++;
            return;
        }
        int n = nums.size();
        for (int i = idx; i < n; i++) {
            if (target - nums[i] >= 0) {
                search(target - nums[i], nums, i);
            }
        }
    }

    int change(int target, vector<int> &nums) {
        // write code here
        int n = nums.size();
        sort(nums.begin(), nums.end(), greater<int>());
        search(target, nums, 0);
        return res;
    }
};

// 动态规划
// 时间复杂度：O(n)
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param target int整型
     * @param nums int整型vector
     * @return int整型
     */
    int change(int target, vector<int> &nums) {
        // write code here
        int n = nums.size();
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (int j = 0; j < n; j++) {
            for (int i = 0; i <= target; i++) {
                if (i - nums[j] >= 0) {
                    dp[i] += dp[i - nums[j]];
                }
            }
        }
        return dp[target];
    }
};