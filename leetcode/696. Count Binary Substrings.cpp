// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    int countBinarySubstrings(string s) {
        int last = 0, curr = 1, res = 0;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i - 1]) {
                curr++;
            } else {
                last = curr;
                curr = 1;
            }
            if (last >= curr) res++;

        }
        return res;
    }
};