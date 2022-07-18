// 遍历
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    vector <vector<int>> removeInterval(vector <vector<int>> &intervals, vector<int> &toBeRemoved) {
        vector <vector<int>> res;
        int n = intervals.size();
        int left = toBeRemoved[0], right = toBeRemoved[1];

        for (int i = 0; i < n; i++) {
            int start = intervals[i][0], end = intervals[i][1];
            if (left > end) {
                res.push_back(intervals[i]);
            } else if (right < start) {
                res.push_back(intervals[i]);
            } else if (left > start && right < end) {
                res.push_back(vector < int > {start, left});
                res.push_back(vector < int > {right, end});
            } else if (left < end && start < left) {
                res.push_back(vector < int > {start, left});
            } else if (start < right && right < end) {
                res.push_back(vector < int > {right, end});
            }
        }

        return res;
    }
};