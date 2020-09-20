// 动态规划
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    int integerBreak(int n) {
        vector<int> record = {0,1,1,2,4,6,9};
        // record.push_back(0);  // 0
        // record.push_back(1);  // 1
        // record.push_back(1);  // 2
        // record.push_back(2);  // 3
        // record.push_back(4);  // 4
        // record.push_back(6);  // 5
        // record.push_back(9);  // 6
        for (int i = 7; i <= n; i++) {
            int num = max(record[i-3]*3, record[i-2]*2);
            record.push_back(num);
        }
        return record[n];
    }
};