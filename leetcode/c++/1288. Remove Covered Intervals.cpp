// 排序+遍历
// 时间复杂度：O(nlogn)
// 空间复杂度：O(n)
class Solution {
public:
    int removeCoveredIntervals(vector <vector<int>> &intervals) {
        int n = intervals.size();
        if (n == 0) return 0;
        sort(intervals.begin(), intervals.end(), [&](const vector<int> &a, const vector<int> &b) {
            if (a[0] != b[0]) {
                return a[0] < b[0];
            } else {
                return a[1] > b[1];
            }
        });
        int res = 0;
        vector <vector<int>> tmp;
        tmp.push_back(intervals[0]);
        for (int i = 1; i < n; i++) {
            int start = intervals[i][0], end = intervals[i][1];
            if (start >= tmp.back()[0] && end <= tmp.back()[1]) {
                res++;
            } else {
                tmp.push_back(vector < int > {start, end});
            }
        }

        return n - res;
    }
};