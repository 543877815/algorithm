// 哈希表
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int n = s.size();
        unordered_map<int, int> record;
        for (int i = 0; i < n; i++) {
            if (record.find(s[i]) == record.end()) {
                record[s[i]] = i;
            }
        }

        int res = -1;
        for (int i = n - 1; i >= 0; i--) {
            if (record.find(s[i]) != record.end()) {
                res = max(res, i - 1 - record[s[i]]);
            }
        }

        return res;
    }
};