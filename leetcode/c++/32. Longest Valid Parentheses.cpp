// 栈
// 时间复杂度：O(n)
// 空间复杂的：O(n)
class Solution {
public:
    /**
     *
     * @param s string字符串
     * @return int整型
     */
    int longestValidParentheses(string s) {
        // write code here
        stack<int> sk;
        int n = s.size();
        int res = 0;
        sk.push(-1);
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                sk.push(i);
            } else {
                if (sk.size() > 1) {
                    sk.pop();
                    res = max(res, i - sk.top());
                } else {
                    sk.top() = i;
                }
            }
        }
        return res;
    }
};

// 动态规划
// case: (  )  (  (  )  (  )  )
// dp:   0  2  0  0  2  0  4  8
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    int longestValidParentheses(string s) {
        // write code here
        int n = s.size();
        if (n < 2) return 0;
        vector<int> dp(n, 0);
        if (s[0] == '(' && s[1] == ')') dp[1] = 2;
        int res = max(0, dp[1]);
        for (int i = 2; i < n; i++) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    dp[i] = dp[i - 2] + 2;
                } else if (i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(') {
                    dp[i] = dp[i - 1] + (i - dp[i - 1] - 2 >= 0 ? dp[i - dp[i - 1] - 2] : 0) + 2;
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};