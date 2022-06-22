// 贪心+位运算
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.size();
        int res = 0;
        int num = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0') {
                res++;
            } else {
                if (res < 31 && num + (1 << res) <= k) {
                    num += (1 << (n - i - 1));
                    res++;
                }
            }
        }

        return res;
    }
};