// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        int right = 0;
        for (int i = 1; i < n; i++) {
            right += (s[i] == '1');
        }
        int left = s[0] == '0';
        int res = right + left;
        for (int i = 1; i < n - 1; i++) {
            int isOne = (s[i] == '1');
            int isZero = (s[i] == '0');
            left += isZero;
            right -= isOne;
            res = max(res, right + left);
        }

        return res;
    }
};