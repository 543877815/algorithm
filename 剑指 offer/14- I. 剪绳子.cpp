// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    int cuttingRope(int n) {
        vector<int> record = {0,1,1,2,4,6,9};
        for (int i = 7; i <= n; i++) {
            int num = max(record[i-3]*3, record[i-2]*2);
            record.push_back(num);
        }
        return record[n];
    }
};