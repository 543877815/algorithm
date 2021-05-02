// 哈希表
// 时间复杂度：O(nm)
// 空间复杂度：O(nm)
class Solution {
public:
    int leastBricks(vector <vector<int>> &wall) {
        int n = wall.size();
        unordered_map<int, int> count;
        int divide = 0;
        for (int i = 0; i < n; i++) {
            int m = wall[i].size();
            int sum = 0;
            for (int j = 0; j < m - 1; j++) {
                sum += wall[i][j];
                count[sum]++;
                divide = max(divide, count[sum]);
            }
        }

        return n - divide;
    }
};