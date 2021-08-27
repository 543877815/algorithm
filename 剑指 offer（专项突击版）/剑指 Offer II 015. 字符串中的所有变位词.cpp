// 滑动窗口
// 时间复杂度：O(n+m)
// 空间复杂度：O(m)
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        int n = s.size(), m = p.size();
        if (n < m) return res;
        vector<int> freq_s = vector<int>(26, 0);
        vector<int> freq_p = vector<int>(26, 0);
        for (int i = 0; i < m; i++) {
            freq_s[s[i] - 'a']++;
            freq_p[p[i] - 'a']++;
        }
        int left = 0, right = m;
        if (freq_s == freq_p) res.push_back(left);
        while (right < n) {
            freq_s[s[left++] - 'a']--;
            freq_s[s[right++] - 'a']++;
            if (freq_s == freq_p) res.push_back(left);
        }
        return res;
    }
};