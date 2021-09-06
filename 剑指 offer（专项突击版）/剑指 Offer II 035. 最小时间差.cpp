// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    int calc(string a, string b) {
        int n = a.size();
        int minite_a = (a[3] - '0') * 10 + a[4] - '0';
        int minite_b = (b[3] - '0') * 10 + b[4] - '0';
        int minite_dis = minite_b - minite_a;
        bool hour_sub = false;
        if (minite_dis < 0) {
            minite_dis += 60;
            hour_sub = true;
        }
        int hour_a = (a[0] - '0') * 10 + a[1] - '0';
        int hour_b = (b[0] - '0') * 10 + b[1] - '0';
        int hour_dis = hour_b - hour_a - hour_sub;

        int res = hour_dis * 60 + minite_dis;
        return res > 720 ? 1440 - res : res;
    }

    int findMinDifference(vector <string> &timePoints) {
        int n = timePoints.size();
        sort(timePoints.begin(), timePoints.end());
        int res = INT_MAX;
        for (int i = 1; i < n; i++) {
            res = min(res, calc(timePoints[i - 1], timePoints[i]));
        }
        res = min(res, calc(timePoints[0], timePoints[n - 1]));
        return res;
    }
};