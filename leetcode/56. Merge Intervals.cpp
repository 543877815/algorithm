// 根据begin排序
// 时间复杂度：O(nlogn)
// 空间复杂度：O(n)
bool compare(const vector<int> &a, const vector<int> &b) {
    if (a[0] != b[0]) return a[0] < b[0];
    return a[1] < b[1];
}

class Solution {
public:
    vector <vector<int>> merge(vector <vector<int>> &intervals) {
        int n = intervals.size();
        vector <vector<int>> res;
        if (n == 0) return res;

        sort(intervals.begin(), intervals.end(), compare);

        vector<bool> remain(n, true);
        for (int i = 0; i < n - 1; i++) {
            if (intervals[i][1] >= intervals[i + 1][0]) {
                intervals[i + 1][0] = intervals[i][0];
                if (intervals[i][1] >= intervals[i + 1][1]) {
                    intervals[i + 1][1] = intervals[i][1];
                }
                remain[i] = false;
            }
        }

        for (int i = 0; i < n; i++) {
            if (remain[i]) res.push_back(intervals[i]);
        }

        return res;
    }
};



// 根据begin排序
// 时间复杂度：O(nlogn)
// 空间复杂度：O(logn)
bool compare(const vector<int> &a, const vector<int> &b) {
    if (a[0] != b[0]) return a[0] < b[0];
    return a[1] < b[1];
}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> res;
        if (n == 0) return res;
        sort(intervals.begin(), intervals.end(), compare);
        for (int i = 0; i < n; i++) {
            if (i != n - 1 && intervals[i][1] >= intervals[i+1][0]) {
                intervals[i+1][0] = intervals[i][0];
                if (intervals[i][1] >= intervals[i+1][1]) {
                    intervals[i+1][1] = intervals[i][1];
                }
            } else {
                res.push_back({intervals[i][0], intervals[i][1]});
            }
        }
        return res;
    }
};