// 位运算+哈希表
// 时间复杂度：O(n^2 + L)
// 空间复杂度：O(L)
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        unordered_map<int, int> record;
        for (int i = 0; i < n; i++) {
            int num = 0;
            int m = words[i].size();
            for (int j = 0; j < m; j++) {
                int logit = words[i][j] - 'a';
                num |= (1 << logit);
            }
            record[num] = max(record[num], m);
        }

        int res = 0;
        for (auto &[key1, value1] : record) {
            for (auto &[key2, value2] : record) {
                if (key1 != key2 && (key1 & key2) == 0) res = max(res, value1 * value2);
            }
        }

        return res;
    }
};