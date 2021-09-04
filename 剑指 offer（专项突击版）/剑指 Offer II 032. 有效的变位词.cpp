// 快速排序
// 时间复杂度：O(nlogn)
// 空间复杂度：O(logn)
class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size(), m = t.size();
        if (s == t) return false;
        if (n != m) return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};

// 哈希表
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size(), m = t.size();
        if (n != m || s == t) return false;
        vector<int> freq_s = vector<int> (26, 0);
        vector<int> freq_t = vector<int> (26, 0);
        for (int i = 0; i < n; i++) {
            freq_s[s[i] - 'a']++;
            freq_t[t[i] - 'a']++;
        }

        return freq_s == freq_t;
    }
};