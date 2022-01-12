// By refer to https://leetcode-cn.com/problems/elimination-game/solution/xiao-chu-you-xi-by-leetcode-solution-ydpb/
// 等差数列模拟
// 时间复杂度：O(lgn)
// 空间复杂度：O(1)
class Solution {
public:
    int lastRemaining(int n) {
        int a1 = 1;
        int k = 0, cnt = n, step = 1;
        while (cnt > 1) {
            if (k % 2 == 0) { // 正向
                a1 = a1 + step;
            } else { // 反向
                a1 = (cnt % 2 == 0) ? a1 : a1 + step;
            }
            k++;
            cnt = cnt >> 1;
            step = step << 1;
        }
        return a1;
    }
};

// By refer to: https://leetcode-cn.com/problems/elimination-game/solution/wo-hua-yi-bian-jiu-kan-dong-de-ti-jie-ni-k2uj/
class Solution {
public:
    int lastRemaining(int n) {
        int head = 1;
        int step = 1;
        bool left = true;
        while (n > 1) {
            if (left) {
                head = head + step;
                left = false;
            } else {
                if (n % 2 == 1) head = head + step;
                left = true;
            }
            step *= 2;
            n /= 2;
        }

        return head;
    }
};