// 贪心算法
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    int balancedStringSplit(string s) {
        int n = s.size();
        int res = 0;
        int leftSum = 0, rightSum = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'L') leftSum++;
            else rightSum++;
            if (leftSum == rightSum) res++;
        }

        return res;
    }
};