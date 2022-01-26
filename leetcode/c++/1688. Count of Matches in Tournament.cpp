// 数学
// 时间复杂度：O(1)
// 空间复杂度：O(1)
class Solution {
public:
    int numberOfMatches(int n) {
        return n - 1;
    }
};

// 模拟
// 时间复杂度：O(logn)
// 空间复杂度：O(1)
class Solution {
public:
    int numberOfMatches(int n) {
        int res = 0;
        while (n > 1) {
            if (n % 2 == 0) {
                n = n / 2;
                res += n;
            } else {
                res += (n - 1) / 2;
                n = (n - 1) / 2 + 1;
            }
        }

        return res;
    }
};