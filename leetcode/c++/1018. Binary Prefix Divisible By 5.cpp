// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool> res;
        int n = A.size();
        int tmp = 0;
        for (int i = 0; i < n; i++) {
            tmp = (tmp * 2 + A[i]) % 10;
            if (tmp % 5 == 0) res.push_back(true);
            else res.push_back(false);
        }

        return res;
    }
};