// 哈希表
// 时间复杂度：O(22n)
// 空间复杂度：O(n)
class Solution {
public:
    int countPairs(vector<int> &deliciousness) {
        unordered_map<long, long> record;
        int n = deliciousness.size();
        for (int i = 0; i < n; i++) {
            record[deliciousness[i]]++;
        }
        vector<int> pow2(22);
        for (int i = 0; i < 22; i++) {
            if (i == 0) pow2[i] = 1;
            else pow2[i] = pow2[i - 1] * 2;
        }

        long long res = 0;
        for (auto &[key, value] : record) {
            for (int i = 0; i < 22; i++) {
                int dis = pow2[i] - key;
                if (record.count(dis) && key <= dis) {
                    if (key < dis) res += record[key] * record[dis];
                    else res += value * (value - 1) / 2;
                }
            }

        }
        return res % 1000000007;
    }
};