
// 时间复杂度：O(logn)
// 空间复杂度：O(1)
bool isPowerOfTwo(int n) {
    if (n % 2 == 1 && n != 1) return false;
    long long int ans = 1;
    while (ans != n) {
        if (ans > n) return false;
        ans *= 2;
    }
    return true;
}

// 二进制表示
// 时间复杂度：O(1)
// 空间复杂度：O(1)
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }
};

// 判断是否为最大 22 的幂的约数
// 时间复杂度：O(1)
// 空间复杂度：O(1)
class Solution {
private:
    static constexpr int BIG = 1 << 30;

public:
    bool isPowerOfTwo(int n) {
        return n > 0 && BIG % n == 0;
    }
};

