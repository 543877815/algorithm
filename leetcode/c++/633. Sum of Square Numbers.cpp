// 使用 sqrt()
// 空间复杂度：O(1)
// 时间复杂度：O(sqrt(n))
class Solution {
public:
    bool judgeSquareSum(int c) {
        for (long i = 0; c >= i * i; i++) {
            int a = c - i * i;
            int b = (int) sqrt(a);
            if (b * b == a) return true;
        }
        return false;
    }
};

// 双指针
// 空间复杂度：O(1)
// 时间复杂度：O(sqrt(n))
class Solution {
public:
    bool judgeSquareSum(int c) {
        long left = 0;
        long right = (long) sqrt(c);
        while (left <= right) {
            long sum = left * left + right * right;
            if (sum == c) return true;
            else if (sum > c) {
                right--;
            } else {
                left++;
            }
        }
        return false;
    }
};

// 费马平方和定理
// 空间复杂度：O(1)
// 时间复杂度：O(sqrt(n))
class Solution {
public:
    bool judgeSquareSum(int c) {
        for (int i = 2; i * i <= c; i++) {
            if (c % i != 0) continue;
            int exp = 0;
            while (c % i == 0) {
                c /= i;
                exp++;
            }

            if (i % 4 == 3 && exp % 2 != 0) return false;
        }
        return c % 4 != 3;
    }
};