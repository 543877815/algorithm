// __builtin_popcount 计算二进制中多少个1
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    vector<int> findClosedNumbers(int num) {
        int n = __builtin_popcount(num);
        int a, b;
        for (a = num + 1; a > 0; ++a) {
            if (__builtin_popcount(a) == n) break;
        }
        for (b = num - 1; b > 0; --b) {
            if (__builtin_popcount(b) == n) break;
        }
        return {a > 0 ? a : -1, b > 0 ? b : -1};
    }
};