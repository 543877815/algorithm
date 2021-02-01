// 时间复杂度：O(n+m)
// 空间复杂度：O(n)
class Solution {
public:
    vector<int> fairCandySwap(vector<int> &A, vector<int> &B) {
        int A_sum = accumulate(A.begin(), A.end(), 0);
        int B_sum = accumulate(B.begin(), B.end(), 0);
        int delta = (A_sum - B_sum) / 2;
        unordered_set<int> record(A.begin(), A.end());
        for (auto &y : B) {
            int x = y + delta;
            if (record.count(x)) {
                return {x, y};
            }
        }
        return {};
    }
};