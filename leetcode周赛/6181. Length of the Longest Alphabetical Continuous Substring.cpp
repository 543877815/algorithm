// 时间复杂度：O(n)
// 空间复杂的：O(1)
class Solution {
public:
    int longestContinuousSubstring(string s) {
        int n = s.size();
        int count = 1;
        int res = 1;
        for (int i = 0; i < n - 1; i++) {
            if (s[i + 1] - s[i] == 1) {
                count++;
            } else {
                res = max(res, count);
                count = 1;
            }
        }

        return max(res, count);
    }
};