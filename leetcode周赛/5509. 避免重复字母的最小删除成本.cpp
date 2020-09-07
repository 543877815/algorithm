// 滑动窗口
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    int minCost(string s, vector<int> &cost) {
        int n = s.size();
        if (n == 0) return 0;
        int left = 0, right = 0, sum = 0;
        while (left < n && right < n) {
            if (right < n && s[right] != s[right + 1]) {
                right++;
                left = right;
            } else {
                while (right < n && s[right] == s[right + 1]) right++;
                int max = INT_MIN;
                for (int i = left; i <= right; i++) {
                    if (max < cost[i]) {
                        max = cost[i];
                    }
                    sum += cost[i];
                }
                sum -= max;
            }
        }
        return sum;
    }
};