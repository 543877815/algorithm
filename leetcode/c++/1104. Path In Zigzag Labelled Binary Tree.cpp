// 数学
// 时间复杂度：O(logn)
// 空间复杂度：O(logn)
class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> record = vector<int>(20);  // 2 ^ 20 = 1048576 > 10 ^ 6
        for (int i = 0; i < record.size(); i++) {
            record[i] = i == 0 ? 1 : record[i - 1] * 2;
        }

        int index = (int) log2(label);

        vector<int> res;
        while (label != 0) {
            res.push_back(label);
            label /= 2;
        }

        reverse(res.begin(), res.end());
        for (int i = 0; i < res.size(); i++) {
            if (index % 2 == 0 && i % 2 == 1) {
                res[i] = record[i + 1] - 1 - res[i] + record[i];
            } else if (index % 2 == 1 && i % 2 == 0) {
                res[i] = record[i + 1] - 1 - res[i] + record[i];
            }
        }
        return res;
    }
};