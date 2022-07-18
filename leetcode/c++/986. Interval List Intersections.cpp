// 排序+双指针遍历
// 时间复杂度：O(n+m)
// 空间复杂度：O(n+m)
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> res;
        int n = firstList.size(), m = secondList.size();
        int i = 0, j = 0;

        while (i < n && j < m) {
            int start1 = firstList[i][0], end1 = firstList[i][1];
            int start2 = secondList[j][0], end2 = secondList[j][1];
            if (start1 <= end2 && end1 >= end2) {
                int start = max(start1, start2);
                int end = min(end1, end2);
                res.push_back(vector<int>{start, end});
                j++;
            } else if (start2 <= end1 && end2 >= end1){
                int start = max(start1, start2);
                int end = min(end1, end2);
                res.push_back(vector<int>{start, end});
                i++;
            } else if (end1 < start2) {
                i++;
            } else if (end2 < start1) {
                j++;
            }
        }

        return res;
    }
};