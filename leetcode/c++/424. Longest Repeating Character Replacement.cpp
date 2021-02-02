// 双指针 滑动窗口
// 空间复杂度：O(26)
// 时间复杂度：O(n)
class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> num(26, 0);
        int n = s.size();
        int maxn = 0;
        int left = 0, right = 0;
        while (right < n) {
            num[s[right] - 'A']++;
            maxn = max(maxn, num[s[right] - 'A']);
            if (right - left + 1 - maxn > k) {
                num[s[left] - 'A']--;
                left++;
            }
            right++;
        }
        return right - left;
    }
};