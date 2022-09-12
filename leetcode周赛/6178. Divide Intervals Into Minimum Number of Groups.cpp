// 时间复杂度：O(nlogn)
// 空间复杂度：O(n)
class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n = intervals.size();
        map<int, int> record;
        for (int i = 0; i < n; i++) {
            int start = intervals[i][0], end = intervals[i][1];
            record[start]++;
            record[end+1]--;
        }

        int presum = 0;
        int res = 0;
        for (auto &[key, value]: record) {
            presum += value;
            res = max(res, presum);
        }

        return res;
    }
};