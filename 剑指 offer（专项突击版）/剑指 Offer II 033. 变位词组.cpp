// 哈希表
// 时间复杂度：O(nk)
// 空间复杂度：O(26n)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string, vector<string>> hashmap;
        for (int i = 0; i < n; i++) {
            int code = 0;
            vector<int> freq = vector<int>(26, 0);
            for (int j = 0; j < strs[i].size(); j++){
                freq[strs[i][j] - 'a']++;
            }
            string freq_str;
            for (int k = 0; k < 26; i++) {
                freq_str = freq_str + char(int('a') + k) + to_string(freq[k]);
            }
            hashmap[freq_str].push_back(strs[i]);
        }
        vector<vector<string>> res;
        for (auto &[key, value]: hashmap) {
            res.push_back(value);
        }

        return res;
    }
};