// 动态规划
// 时间复杂度：O(n^2)
// 空间复杂度：O(n)
class Solution {
public:
    bool wordBreak(string s, vector <string> &wordDict) {
        int n = s.size();
        if (n == 0) return true;
        if (wordDict.size() == 0) return false;
        unordered_set <string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        int min_len = 0, max_len = 0;

        for (int i = 0; i < wordDict.size(); i++) {
            int len = wordDict[i].size();
            max_len = max(max_len, len);
            min_len = min(min_len, len);
        }

        for (int i = min_len; i <= n; i++) {
            for (int j = std::max(0, i - max_len); j < i; j++) {
                if (dp[j] && wordSet.find(s.substr(j, i - j)) != wordSet.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};