// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if (timeSeries.size() == 0 || duration == 0) return 0;
        int res = 0;
        for (int i = 0; i < timeSeries.size() - 1; i++) {
            int distance = timeSeries[i+1]-timeSeries[i];
            if (distance<=duration) res += distance;
            else res += duration;
        }
        return res + duration;
    }
};