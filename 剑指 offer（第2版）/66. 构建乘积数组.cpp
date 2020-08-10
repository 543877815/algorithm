// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    vector<int> constructArr(vector<int> &a) {
        int n = a.size();
        if (n == 0) return {};
        vector<int> res(n, 1);
        for (int i = 0, product = 1; i < n; product *= a[i], i++) {
            res[i] *= product;
        }
        for (int i = n - 1, product = 1; i >= 0; product *= a[i], i--) {
            res[i] *= product;
        }
        return res;
    }
};