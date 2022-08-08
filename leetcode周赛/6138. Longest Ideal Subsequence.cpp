// 动态规划
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    int longestIdealString(string s, int k) {
        int n = s.size();
        if (n == 0) return 0;
        unordered_map<char, int> hashmap; // 以字母 i 结尾的最长理想子序列
        int res = 1;
        for (int i = 0; i < n; i++) {
            int max_num = 1;
            for (int j = 0; j < 26; j++) {
                char c = j + 'a';
                if (hashmap.count(c) && abs(s[i] - c) <= k) {
                    max_num = max(max_num, hashmap[c] + 1);
                }
            }

            hashmap[s[i]] = max_num;
            res = max(res, max_num);
        }

        return res;
    }
};