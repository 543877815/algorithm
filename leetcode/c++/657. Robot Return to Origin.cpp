// 时间复杂度：O(1)
// 空间复杂度：O(n)
class Solution {
public:
    bool judgeCircle(string moves) {
        int n = moves.size();
        if (n == 0) return true;
        int x = 0, y = 0;
        for (int i = 0; i < n; i++) {
            if (moves[i] == 'L') {
                x--;
            } else if (moves[i] == 'R') {
                x++;
            } else if (moves[i] == 'U') {
                y++;
            } else if (moves[i] == 'D') {
                y--;
            }
        }
        return x == 0 && y == 0;
    }
};