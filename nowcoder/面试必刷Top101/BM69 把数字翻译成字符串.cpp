// 动态规划
// 时间复杂度：O(n)
// 空间复杂度：O(n)
/*
 *  step 1：用辅助数组dp表示前i个数的译码方法有多少种。
 *  step 2：对于一个数，我们可以直接译码它，也可以将其与前面的1或者2组合起来译码：如果直接译码，则dp[i]=dp[i?1]；如果组合译码，则dp[i]=dp[i?2]。
 *  step 3：对于只有一种译码方式的，选上种dp[i?1]即可，对于满足两种译码方式（10，20不能）则是dp[i?1]+dp[i?2]
 *  step 4：依次相加，最后的dp[length]即为所求答案。
 */
class Solution {
public:
    /**
     * 解码
     * @param nums string字符串 数字串
     * @return int整型
     */
    int solve(string nums) {
        // write code here
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) {
            if (nums[0] == '0') return 0;
            else return 1;
        };
        vector<int> dp(n);
        dp[0] = 1;
        if (nums[1] == '0') {
            dp[1] = dp[0];
        } else if (nums[0] == '1' || (nums[0] == '2' && nums[1] <= '6')) {
            dp[1] = 2;
        } else {
            dp[1] = dp[0];
        }

        for (int i = 2; i < n; i++) {
            if (nums[i] == '0') {
                if (nums[i-1] > '2') return 0;
                dp[i] = dp[i-1];
            } else if (nums[i-1]=='1' && nums[i] != '0') {
                dp[i] = dp[i-2] + dp[i-1];
            } else if (nums[i-1]=='2'&& nums[i] <='6' && nums[i] > '0') {
                dp[i] = dp[i-2] + dp[i-1];
            } else {
                dp[i] = dp[i-1];
            }
        }

        return dp[n-1];
    }
};