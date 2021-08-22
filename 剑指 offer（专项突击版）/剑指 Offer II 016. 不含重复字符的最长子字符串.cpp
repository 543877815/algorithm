// 哈希表
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int freq[256] = {0};
        int l = 0, r = 0;
        int res = 0;
        while (l < s.size()) {
            if (r < s.size() && freq[s[r]] == 0) {
                freq[s[r++]]++;
            } else {
                freq[s[l++]]--;
            }
            res = max(res, r - l);
        }

        return res;
    }
};