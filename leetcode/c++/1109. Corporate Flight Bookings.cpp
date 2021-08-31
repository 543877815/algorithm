// 前缀和
// 空间复杂度：O(n+m)
// 时间复杂度：O(1)
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> res = vector<int>(n, 0);
        int m = bookings.size();
        for (int i = 0; i < m; i++) {
            int first = bookings[i][0] - 1;
            int last = bookings[i][1] - 1;
            int seat = bookings[i][2];
            res[first] += seat;
            if (last + 1 < n) res[last + 1] -= seat;
        }

        for (int i = 1; i < n; i++) {
            res[i] += res[i-1];
        }

        return res;
    }
};