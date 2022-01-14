class Solution {
public:
    int mySqrt(int x) {
        return (int) sqrt(x);
    }
};

// 二分查找
// 时间复杂度：O(logx)
// 空间复杂度：O(1)
class Solution {
public:
    int mySqrt(int x) {
        // return (int)sqrt(x);
        int begin = 0;
        int end = x;
        int middle = (begin + end) / 2;
        if (x == 0) return 0;
        if (x == 1) return 1;
        while (begin <= end) {
            if (middle == x / middle) {
                return middle;
            } else if (middle < x / middle) {
                begin = middle + 1;
            } else {
                end = middle - 1;
            }
            middle = (begin + end) / 2;
        }
        return end;
    }
};