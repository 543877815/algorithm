// 一次遍历
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    int maxPower(string s) {
        int res = 1;
        int n = s.size();
        char init = 'A';
        int count = 1;
        for (int i = 0; i < n; i++) {
            if (s[i] != init) {
                init = s[i];
                count = 1;
            } else {
                count++;
                res = max(res, count);
            }
        }

        return res;
    }
};