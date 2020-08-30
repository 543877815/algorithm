// https://leetcode-cn.com/problems/shortest-palindrome/solution/zui-duan-hui-wen-chuan-by-leetcode-solution/
// 字符串哈希
// 时间复杂度：O(|s|)
// 空间复杂度：O(1)
class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        int base = 131, mod = 1000000007;
        int left = 0, right = 0, mul = 1;
        int best = -1;
        // 12345
        // left: base^4*1+base^3*2+base^2*3+base^1*4+base^0*5
        // right: base^0*+base^1*2+base^2*3+base^3*4+base^4*5

        for (int i = 0; i < n; i++) {
            left = ((long long) left * base + s[i]) % mod;  // hash值：十进制
            right = (right + (long long) mul * s[i]) % mod;
            if (left == right) best = i;
            mul = (long long) mul * base % mod;
        }
        string add = (best == n - 1 ? "" : s.substr(best + 1, n));
        reverse(add.begin(), add.end());
        return add + s;
    }
};


// KMP
class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        vector<int> fail(n, -1);
        for (int i = 1; i < n; ++i) {
            int j = fail[i - 1];
            while (j != -1 && s[j + 1] != s[i]) {
                j = fail[j];
            }
            if (s[j + 1] == s[i]) {
                fail[i] = j + 1;
            }
        }
        int best = -1;
        for (int i = n - 1; i >= 0; --i) {
            while (best != -1 && s[best + 1] != s[i]) {
                best = fail[best];
            }
            if (s[best + 1] == s[i]) {
                ++best;
            }
        }
        string add = (best == n - 1 ? "" : s.substr(best + 1, n));
        reverse(add.begin(), add.end());
        return add + s;
    }
};
