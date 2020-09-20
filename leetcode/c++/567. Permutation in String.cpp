// 滑动窗口
// 时间复杂度：O(mn)
// 空间复杂度：O(k)
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int left = 0;
        int right = 0;
        vector<int> freq_s1(26,0), freq_s2(26,0);
        for (auto &c: s1) {
            freq_s1[c-'a']++;
        }
        while(right < s2.size()) {
            freq_s2[s2[right]-'a']++;
            if (right-left+1<s1.size()) {
                right++;
                continue;
            }
            if (freq_s1 == freq_s2) return true;
            freq_s2[s2[left]-'a']--;
            left++;
            right++;
        }
        return false;
    }
};