// n&n-1会让最低位变成0
// 时间复杂度：O(1)
// 空间复杂度：O(1)
class Solution {
public:
    int NumberOf1(int n) {
        int ans = 0;
        while (n != 0) {
            ++ans;
            n = n & (n - 1);
        }
        return ans;
    }
};

// 按位比较
// 时间复杂度：O(1)
// 空间复杂度：O(1)
class Solution {
public:
    int NumberOf1(int n) {
        int res = 0;
        //遍历32位
        for (int i = 0; i < 32; i++) {
            //按位比较
            if ((n & (1 << i)) != 0)
                res++;
        }
        return res;
    }
};