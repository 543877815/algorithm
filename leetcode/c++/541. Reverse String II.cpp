// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();
        int curr = 0;
        while (curr < n) {
            int new_curr = min(curr + k, n);
            reverse(s.begin() + curr, s.begin() + new_curr);
            curr += 2 * k;
        }
        return s;
    }
};