// 时间复杂度：O(n+m)
// 空间复杂度：O(1)
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int n = name.size(), m = typed.size();
        if (n > m) return false;
        int i = 0, j = 0;
        while (i < n && j < m) {
            if (name[i] == typed[j]) {
                i++;
                j++;
                continue;
            }
            if (i > 0 && name[i - 1] == typed[j]) {
                j++;
                continue;
            }
            if (name[i] != typed[j]) break;
        }
        while (j < m && typed[j] == name[n - 1]) j++;
        return i == n && j == m;
    }
};