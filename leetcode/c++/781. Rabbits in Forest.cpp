// 哈希表 + 数学
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    int numRabbits(vector<int> &answers) {
        int n = answers.size();
        if (n == 0) return 0;
        unordered_map<int, int> record;
        for (int i = 0; i < n; i++) {
            record[answers[i]]++;
        }
        int res = 0;
        for (auto &[key, val] : record) {
            if (val % (key + 1) == 0)
                res += (val / (key + 1)) * (key + 1);
            else
                res += (val / (key + 1) + 1) * (key + 1);
        }
        return res;
    }
};