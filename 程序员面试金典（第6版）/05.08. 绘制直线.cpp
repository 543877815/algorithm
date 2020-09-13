// 时间复杂度：O(x2-x1)
// 空间复杂度：O(length)
class Solution {
public:
    vector<int> drawLine(int length, int w, int x1, int x2, int y) {
        vector<int> res(length, 0);
        for (int i = x1; i <= x2; ++i)
            res[i / 32 + y * w / 32] |= (1 << (31 - i % 32));
        return res;
    }
};