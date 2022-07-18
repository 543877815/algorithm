// 时间复杂度：O(nlogn)
// 空间复杂度：O(n)
class Solution {
public:
    vector<int> findRightInterval(vector <vector<int>> &intervals) {
        int n = intervals.size();
        vector<int> res;
        if (n == 0) return res;
        vector<int> id(n);
        iota(id.begin(), id.end(), 0);
        sort(id.begin(), id.end(), [&](int i, int j) {
            return intervals[i][0] < intervals[j][0];
        });
        vector<int> starts(n);
        for (int i = 0; i < n; i++) {
            starts[i] = intervals[i][0];
        }

        sort(starts.begin(), starts.end());
        for (int i = 0; i < n; i++) {
            int idx = lower_bound(starts.begin(), starts.end(), intervals[i][1]) - starts.begin();
            res.push_back(idx == n ? -1 : id[idx]);
        }

        return res;
    }
};