// 贪心算法，计算保留的区间再相减
// 时间复杂度：O(n)
// 空间复杂度：O(1)
bool compare(const vector<int> &a, const vector<int> &b) {
    if (a[1] != b[1]) return a[1] < b[1];
    return a[0] < b[0];
}

class Solution {
public:
    int eraseOverlapIntervals(vector <vector<int>> &intervals) {
        int n = intervals.size();
        if (n == 0) return 0;

        sort(intervals.begin(), intervals.end(), compare);

        int res = 1;
        int pre = 0;
        for (int i = 1; i < n; i++) {
            if (intervals[i][0] >= intervals[pre][1]) {
                res++;
                pre = i;
            }
        }

        return n - res;
    }
};

// 动态规划
// 时间复杂度：O(n^2)
// 空间复杂度：O(n)
bool compare(vector<int> &a, const vector<int> &b) {
    if (a[0] != b[0]) return a[0] < b[0];
    return a[1] < b[1];
}

class Solution {
public:
    int eraseOverlapIntervals(vector <vector<int>> &intervals) {
        int n = intervals.size();
        if (n == 0) return 0;

        sort(intervals.begin(), intervals.end(), compare);

        // dp[i]表示使用intervals[0...i]的区间能构成的最长不重叠序列
        vector<int> dp(n, 1);
        for (int i = 1; i < n; i++) {
            // dp[i]
            for (int j = 0; j < i; j++) {
                if (intervals[i][0] >= intervals[j][1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }

        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            res = max(res, dp[i]);
        }
        return n - res;
    }
};