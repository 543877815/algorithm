// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    int countAsterisks(string s) {
        int n = s.size();
        int count = 0;
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '|') count++;
            if (count % 2 == 0) {
                if (s[i] == '*') res++;
            }
        }
        return res;
    }
};