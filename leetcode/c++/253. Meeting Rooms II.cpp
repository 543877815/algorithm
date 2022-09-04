// ʱ�临�Ӷȣ�O(nlogn)
// �ռ临�Ӷȣ�O(n)
// �������
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int n = intervals.size();
        map<int, int> record;
        for (int i = 0; i < n; i++) {
            int start = intervals[i][0], end = intervals[i][1];
            record[start]++;
            record[end]--;
        }

        int presum = 0;
        int res = 1;
        for (auto &[key, value]: record) {
            presum += value;
            res = max(res, presum);
        }

        return res;
    }
};