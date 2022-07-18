// ʱ�临�Ӷȣ�O(n)
// �ռ临�Ӷȣ�O(1)
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