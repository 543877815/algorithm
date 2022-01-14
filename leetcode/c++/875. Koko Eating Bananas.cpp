// 二分查找
// 时间复杂度：O(nlogC)
// 空间复杂度：O(1)
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = INT_MIN;
        int n = piles.size();
        for (int i = 0; i < n; i++) {
            right = max(right, piles[i]);
        }
        int res = INT_MAX;
        while (left <= right) {
            int cnt = 0;
            int mid = left + (right - left) / 2;
            for (int i = 0; i < n; i++) {
                cnt += piles[i] / mid + (piles[i] % mid == 0 ? 0 : 1);
            }
            if (cnt <= h) {
                res = min(res, mid);
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return res;
    }
};