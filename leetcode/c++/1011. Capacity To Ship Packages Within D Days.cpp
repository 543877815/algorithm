// 二分查找
// 时间复杂度：o(nlog sumweight)
// 空间复杂度：O(1)
class Solution {
public:
    int shipWithinDays(vector<int> &weights, int D) {
        int maxWeight = INT_MIN;
        int sumWeight = 0;
        int n = weights.size();
        for (int i = 0; i < n; i++) {
            maxWeight = max(maxWeight, weights[i]);
            sumWeight += weights[i];
        }
        while (maxWeight < sumWeight) {
            int mid = (sumWeight + maxWeight) / 2;
            int tmp = 0;
            int day = 1;
            for (int i = 0; i < n; i++) {
                tmp += weights[i];
                if (tmp > mid) {
                    day += 1;
                    tmp = weights[i];
                }
            }

            if (day > D) maxWeight = mid + 1;
            else sumWeight = mid;
        }

        return maxWeight;
    }
};