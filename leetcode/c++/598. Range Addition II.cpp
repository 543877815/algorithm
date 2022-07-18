// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    int maxCount(int m, int n, vector <vector<int>> &ops) {
        int mina = m, minb = n;
        for (const auto &op: ops) {
            mina = min(mina, op[0]);
            minb = min(minb, op[1]);
        }
        return mina * minb;
    }
};