// 双指针遍历
// 时间复杂度：O(n^2)
// 空间复杂度：O(1)
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param A string字符串
     * @return int整型
     */
    pair<int, int> expandAroundCenter(const string &s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }

        return {left + 1, right - 1};
    }

    int getLongestPalindrome(string s) {
        // write code here
        int n = s.size();
        int start = 0, end = 0;
        for (int i = 0; i < n; i++) {
            auto [left1, right1] = expandAroundCenter(s, i, i + 1);
            auto [left2, right2] = expandAroundCenter(s, i, i);

            if (right1 - left1 > end - start) {
                end = right1;
                start = left1;
            }

            if (right2 - left2 > end - start) {
                end = right2;
                start = left2;
            }
        }

        return end - start + 1;
    }
};

// 动态规划
// 时间复杂度：O(n^2)
// 空间复杂度：O(n^2)
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param A string字符串
     * @return int整型
     */
    pair<int, int> expandAroundCenter(const string &s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }

        return {left + 1, right - 1};
    }

    int getLongestPalindrome(string s) {
        // write code here
        int n = s.size();
        if (n < 2) return n;
        vector<vector<bool>> dp(n, vector<bool>(n));
        for (int i = 0; i < n; i++) dp[i][i] = true;
        int res = 1;

        // 枚举长度
        for (int L = 2; L <= n; L++) {
            // 枚举左边界，左边界的上限设置可以宽松一些
            for (int i = 0; i < n; i++) {
                int j = L + i - 1;
                // 如果右边界越界则退出当前循环
                if (j >= n) break;

                if (s[i] != s[j]) {
                    dp[i][j] = false;
                } else {
                    if (j - i < 3) {
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                    // 只要 dp[i][L] == true 成立，就表示子串 s[i..L] 是回文，此时记录回文长度和起始位置
                    if (dp[i][j] && j - i + 1 > res) {
                        res = j - i + 1;
                    }
                }
            }
        }
        return res;
    }
};