// 滑动窗口
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    int maxScore(vector<int> &cardPoints, int k) {
        int n = cardPoints.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += cardPoints[i];
        }
        int size = n - k;  // 中间的n-k个牌
        int curr = 0;
        for (int i = 0; i < size; i++) {
            curr += cardPoints[i];
        }
        int res = curr;
        int left = 0, right = size;
        while (right < n && left < n) {
            curr += cardPoints[right++];
            curr -= cardPoints[left++];
            res = min(res, curr);
        }

        return sum - res;
    }
};