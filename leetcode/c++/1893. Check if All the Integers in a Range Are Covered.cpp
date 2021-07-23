// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        int n = ranges.size();
        vector<bool> record = vector<bool> (51, false);
        for (int i = 0; i < n; i++) {
            for (int j = ranges[i][0]; j <= ranges[i][1]; j++) {
                record[j] = true;
            }
        }

        int count = 0;
        for (int i = left; i <= right; i++) {
            if (record[i] == true) count ++;
        }

        return count == right - left + 1;
    }
};