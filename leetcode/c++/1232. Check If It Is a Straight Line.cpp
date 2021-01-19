// 数学一次遍历
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    bool checkStraightLine(vector <vector<int>> &coordinates) {
        int n = coordinates.size();
        if (n == 1) return true;
        int deltaX = coordinates[0][0], deltaY = coordinates[0][1];
        for (int i = 0; i < n; i++) {
            coordinates[i][0] -= deltaX;
            coordinates[i][1] -= deltaY;
        }
        int A = coordinates[1][1], B = -coordinates[1][0];
        for (int i = 2; i < n; i++) {
            int x = coordinates[i][0], y = coordinates[i][1];
            if (A * x + B * y != 0) return false;
        }

        return true;
    }
};