// 一次遍历
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    string toLowerCase(string s) {
        for (auto &x : s) {
            if (x >= 'A' && x <= 'Z') {
                x = x - 'A' + 'a';
            }
        }
        return s;
    }
};