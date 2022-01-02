// 哈希表
// 时间复杂度：O(n)
// 空间复杂度：O(n)

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        unordered_map<int, int> hash;
        int n = score.size();
        vector<string> res(n);
        for (int i = 0; i < n; i++) {
            hash[score[i]] = i;
        }

        sort(score.begin(), score.end(), greater<int>());

        for (int i = 0; i < n; i++) {
            int index = hash[score[i]];
            if (i == 0) {
                res[index] = "Gold Medal";
            } else if (i == 1) {
                res[index] = "Silver Medal";
            } else if (i == 2) {
                res[index] = "Bronze Medal";
            } else {
                res[index] = to_string(i + 1);
            }
        }

        return res;
    }
};