// 排序
// 时间复杂度：O(nlogn)
// 空间复杂度：O(logn)
class Solution {
public:
    int busyStudent(vector<int> &startTime, vector<int> &endTime, int queryTime) {
        int res = 0;
        int n = startTime.size();
        int i = 0, j = 0;
        sort(startTime.begin(), startTime.end());
        sort(endTime.begin(), endTime.end());
        while (i < n && startTime[i] <= queryTime) {
            res++;
            i++;
        }
        while (j < n && endTime[j] < queryTime) {
            res--;
            j++;
        }
        return res;
    }
};