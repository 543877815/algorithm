// 时间复杂度：O(nlogn)
// 空间复杂度：O(1)
class Solution {
public:
    int latestTimeCatchTheBus(vector<int> &buses, vector<int> &passengers, int capacity) {
        int n = buses.size(), m = passengers.size();
        sort(buses.begin(), buses.end());
        sort(passengers.begin(), passengers.end());
        int curr = 0;
        bool isFull = false;
        for (int i = 0; i < n; i++) {
            int leave = buses[i];
            int left = 0, right = m - 1;
            while (left <= right) {
                int mid = (left + right) / 2;
                if (passengers[mid] > leave) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            isFull = left - curr >= capacity ? true : false;
            curr += left - curr > capacity ? capacity : left - curr;

        }
        if (curr == 0) return buses[n - 1];
        curr--;
        int res = isFull ? passengers[curr--] - 1:buses[n - 1];
        while (curr >= 0 && res == passengers[curr]) {
            res--;
            curr--;
        }

        return res;
    }
};
