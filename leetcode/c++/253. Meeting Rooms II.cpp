// 时间复杂度：O(nlogn)
// 空间复杂度：O(n)
// 差分数组
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int n = intervals.size();
        map<int, int> record;
        for (int i = 0; i < n; i++) {
            int start = intervals[i][0], end = intervals[i][1];
            record[start]++;
            record[end]--;
        }

        int presum = 0;
        int res = 1;
        for (auto &[key, value]: record) {
            presum += value;
            res = max(res, presum);
        }

        return res;
    }
};