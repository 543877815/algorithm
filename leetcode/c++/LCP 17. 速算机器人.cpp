// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    int calculate(string s) {
        int x = 1, y = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == 'A') {
                x = 2 * x + y;
            } else if (s[i] == 'B') {
                y = 2 * y + x;
            }
        }

        return x + y;
    }
};