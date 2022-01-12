// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res = {0, 1};
        int digit = 1;
        while (digit < n) {
            int k = res.size();
            for (int i = k - 1; i >= 0; i--) {
                res.push_back((1 << digit) + res[i]);
            }
            digit++;
        }
        return res;
    }
};