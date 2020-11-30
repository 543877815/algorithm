// 贪心算法
// 时间复杂度：O(nlogn)
// 空间复杂度：O(nlogn)
bool compare(vector<int> &a, vector<int>&b) {
    if (a[1] != b[1]) return a[1] < b[1];
    return a[0] < b[0];
}

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int m = points.size();
        if (m == 0) return 0;
        sort(points.begin(), points.end(), compare);
        int end = points[0][1];
        int lastIndex = 0;
        int res = 0;
        for (int i = 1; i < m; i++) {
            if (points[i][0] > end) {
                res ++;
                lastIndex = i;
                end = points[i][1];
            }
        }
        if (m - lastIndex != 0) res++;
        return res;
    }
};
