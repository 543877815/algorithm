// 哈希表
// 时间复杂度：O(n)
// 空间复杂度：O(26)
class Solution {
public:
    string greatestLetter(string s) {
        int n = s.size();
        unordered_map<char, bool> upper_map;
        unordered_map<char, bool> lower_map;
        for (int i = 0; i < n; i++) {
            if (s[i] >= 'a' && s[i] <= 'z') lower_map[s[i]] = true;
            else upper_map[s[i]] = true;
        }

        string res = "";
        for (char i = 'a'; i <= 'z'; i++) {
            if (upper_map[i - 32] && lower_map[i]) res = i;
        }

        res[0] = res[0] >= 'a' ? res[0] - 32 : res[0];

        return res;
    }
};