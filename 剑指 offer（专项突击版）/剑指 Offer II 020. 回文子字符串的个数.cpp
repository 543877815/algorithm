// 双指针
// 时间复杂度：O(n^2)
// 空间复杂度：O(1)
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int res = 0;
        for (int i = 0; i < 2 * n - 1; i++) {
            int left = i / 2, right = i / 2 + i % 2;
            while (left >= 0 && right < n && s[left] == s[right]) {
                left--;
                right++;
                res++;
            }
        }
        return res;
    }
};