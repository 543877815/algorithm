// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        vector<int> record(26, 0);
        if (s1.size() != s2.size()) return false;
        for (int i = 0; i < s1.size(); i++) {
            record[s1[i]-'a']++;
            record[s2[i]-'a']--;
        }
        for (int i = 0; i < record.size(); i++) {
            if (record[i] != 0) return false;
        }
        return true;
    }
};

// 时间复杂度：O(nlogn)
// 空间复杂度：O(1)
class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) return false;
        }
        return true;
    }
};