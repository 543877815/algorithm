// 哈希表
// 时间复杂度：O(n+m)
// 空间复杂度：O(26)
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        if (m < n) return false;
        vector<char> freq_s1 = vector<char>(26, 0);
        vector<char> freq_s2 = vector<char>(26, 0);
        for (int i = 0; i < n; i++) {
            freq_s1[s1[i] - 'a']++;
            freq_s2[s2[i] - 'a']++;
        }
        int left = 0, right = n;
        while (right < m) {
            if (freq_s1 == freq_s2) return true;
            freq_s2[s2[right++] - 'a']++;
            freq_s2[s2[left++] - 'a']--;
        }

        return freq_s2 == freq_s1;
    }
};