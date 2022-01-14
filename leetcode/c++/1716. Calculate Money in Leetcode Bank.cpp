// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    int totalMoney(int n) {
        int init_group = 1 + 2 + 3 + 4 + 5 + 6 + 7;
        int group = n / 7;
        int remain = n % 7;
        int res = 0;
        for (int i = 0; i < group; i++) {
            res += init_group + 7 * i;
        }
        for (int i = 1; i <= remain; i++) {
            res += i;
        }
        res += remain * group;
        return res;
    }
};