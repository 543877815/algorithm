// 曼哈顿距离
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    int ManhattanDistance(int x1, int y1, int x2, int y2) {
        return abs(x1 - x2) + abs(y1 - y2);
    }

    bool escapeGhosts(vector <vector<int>> &ghosts, vector<int> &target) {
        int dis = ManhattanDistance(0, 0, target[0], target[1]);
        int n = ghosts.size();
        for (int i = 0; i < n; i++) {
            if (ManhattanDistance(target[0], target[1], ghosts[i][0], ghosts[i][1]) <= dis) {
                return false;
            }
        }

        return true;
    }
};