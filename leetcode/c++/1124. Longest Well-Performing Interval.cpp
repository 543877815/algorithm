// 时间复杂度：O(n^2)
// 空间复杂度：O(n)
class Solution {
public:
    int longestWPI(vector<int> &hours) {
        int n = hours.size();
        vector<int> presum(n + 1, 0);
        map<int, int> record;
        record[0] = 0;
        for (int i = 0; i < n; i++) {
            if (hours[i] > 8) presum[i + 1] = presum[i] + 1;
            else presum[i + 1] = presum[i] - 1;
            if (!record.count(presum[i + 1])) {
                record[presum[i + 1]] = i + 1;
            }
        }
        int res = 0;
        for (int i = 1; i < n + 1; i++) {
            for (auto &[key, value]: record) {
                if (presum[i] - key > 0) {
                    res = max(res, i - value);
                } else {
                    break;
                }
            }
        }
        return res;
    }
};
