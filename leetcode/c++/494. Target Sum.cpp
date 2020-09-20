// 递归
// 时间复杂度：O(2^n)
// 空间复杂度：O(n)
class Solution {
private:
    int count = 0;

    void search(vector<int> &nums, int index, int sum, int S) {
        if (index == nums.size()) {
            if (sum == S) count++;
            return;
        } else {
            search(nums, index + 1, sum + nums[index], S);
            search(nums, index + 1, sum - nums[index], S);
        }
    }

public:
    int findTargetSumWays(vector<int> &nums, int S) {
        search(nums, 0, 0, S);
        return count;
    }
};


/*
 * S(P)−S(N)=T
 * S(P) + S(N) + S(P) - S(N) = T + S(P) + S(N)
 * 2S(P) = S(Q) + T
 * 正数和的两倍=目标+序列和
 * 转化为0-1背包问题
 */

// 动态规划
// 时间复杂度：O(n)
// 空间复杂度：O(sum)
class Solution {
public:
    int findTargetSumWays(vector<int> &nums, int S) {
        int n = nums.size();
        if (n == 0) return 0;
        unsigned int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }
        if ((sum + S) % 2 == 1 || S > (int) sum) return 0;
        sum = (sum + S) / 2;
        // dp[i]表示和为i的组合数
        vector<int> dp(sum + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = sum; j >= nums[i]; j--) {
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[sum];
    }
};