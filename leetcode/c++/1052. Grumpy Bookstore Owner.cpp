// 滑动窗口
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int X) {
        int n = customers.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (grumpy[i] == 0) {
                sum += customers[i];
            }
        }
        for (int i = 0; i < X; i++) {
            if (grumpy[i] == 1) {
                sum += customers[i];
            }
        }
        int res = sum;
        int left = 0, right = X;
        while (right < n && left < n) {
            if (grumpy[right] == 1) {
                sum += customers[right];
            }
            if (grumpy[left] == 1) {
                sum -= customers[left];
            }
            right++;
            left++;
            res = max(res, sum);
        }
        return res;
    }
};