// 动态规划
// 时间复杂度：O(n)
// 空间复杂度：O(1)

/*
 * dp[i]为str[0..i]的译码方法总数
 * 分情况讨论：（建立最优子结构）
 *    若 s[i] == '0',那么若s[i-1]='1' or '2',则dp[i]=dp[i-2];否则return 0
 *          解释: s[i-1]+s[i]唯一被译码，不增加情况
 *    若 s[i-1] == '1',则dp[i]=dp[i-1]+dp[i-2]
 *          解释：s[i-1]与s[i]分开译码，为dp[i-1];合并译码,为dp[i-2]
 *    若 s[i-1] == '2' 且 '1' <= s[i] <= '6', 则dp[i]=dp[i-1]+dp[i-2]
 * 由分析只，dp[i]仅与前两项有关，故可以用单变量代替dp[]数组，将空间复杂度从O(n)降到O(1)
 */
class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0') return 0;
        int pre = 1, curr = 1;
        for (int i = 1; i < s.size(); i++) {
            int tmp = curr;
            if (s[i] == '0') {
                if (s[i - 1] == '1' || s[i - 1] == '2') curr = pre;
                else return 0;
            } else if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] >= '1' && s[i] <= '6')) {
                curr = curr + pre;
            }
            pre = tmp;
        }
        return curr;
    }
};