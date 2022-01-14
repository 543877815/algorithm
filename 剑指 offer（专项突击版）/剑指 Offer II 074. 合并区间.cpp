// 一次遍历
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        vector<vector<int>> res;
        for (int i = 0; i < n; i++) {
            int L = intervals[i][0], R = intervals[i][1];
            if (res.empty() || res.back()[1] < L) {
                res.push_back(intervals[i]);
            } else {
                res.back()[1] = max(res.back()[1], R);
            }
        }
        return res;
    }
};