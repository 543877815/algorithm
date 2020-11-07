// 动态规划+回溯算法
// 时间复杂度：O(n*2^n)
// 空间复杂度：O(n)
class Solution {
public:
    vector <string> res;
    unordered_set <string> wordSet;
    int max_len = 0, min_len = INT_MAX;

    vector <string> wordBreak(string s, vector <string> &wordDict) {
        if (!wordBreak139(s, wordDict)) return res;
        vector <string> dictTmp;
        dfs(s, dictTmp);
        return res;
    }

    void dfs(string s, vector <string> &dictTmp) {
        if (s.size() == 0) {
            string res_s;
            for (int i = 0; i < dictTmp.size(); i++) {
                res_s += dictTmp[i];
                if (i != dictTmp.size() - 1) res_s += " ";
            }
            res.push_back(res_s);
            return;
        }
        for (int i = min_len; i <= max_len; i++) {
            if (wordSet.find(s.substr(0, i)) != wordSet.end()) {
                dictTmp.push_back(s.substr(0, i));
                if (i <= s.size()) {
                    string tmp = s.substr(i);
                    dfs(tmp, dictTmp);
                }
                dictTmp.pop_back();
            }
        }
    }

    bool wordBreak139(string s, vector <string> &wordDict) {
        int n = s.size();
        if (n == 0) return true;
        if (wordDict.size() == 0) return false;
        wordSet = unordered_set<string>(wordDict.begin(), wordDict.end());
        // dp 表示到第i个字符是否有匹配
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;

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