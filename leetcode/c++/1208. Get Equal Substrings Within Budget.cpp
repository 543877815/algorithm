// 滑动窗口
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        int res = 0;
        int left = 0, right = 0;
        while (right < n && left < n) {
            if (maxCost >= 0) {
                maxCost -= abs(s[right] - t[right]);
                right++;
            } else {
                maxCost += abs(s[left] - t[left]);
                left++;
            }
            if (maxCost >= 0)
                res = max(res, right - left);
        }
        return res;
    }
};