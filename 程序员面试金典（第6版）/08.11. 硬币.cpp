// 等差数列求和
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
private:
    static constexpr int mod = 1000000007;

public:
    int waysToChange(int n) {
        int ans = 0;
        for (int i = 0; i * 25 <= n; ++i) {
            int rest = n - i * 25;
            int a = rest / 10;
            int b = rest % 10 / 5;
            ans = (ans + (long long) (a + 1) * (a + b + 1) % mod) % mod;
        }
        return ans;
    }
};

// 动态规划
// 时间复杂度：O(n)
// 空间复杂度：O(n)