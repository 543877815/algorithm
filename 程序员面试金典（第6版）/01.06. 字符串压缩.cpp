// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    string compressString(string S) {
        string res;
        int i = 0, n = S.size(), count = 1;
        bool init = true;
        for (int i = 0; i < n; i++) {
            if (i > 0) {
                if (S[i] != S[i - 1]) {
                    res += to_string(count) + S[i];
                    count = 1;
                } else {
                    count++;
                }
            } else {
                res += S[i];
            }
        }
        res += to_string(count);
        return res.size() < n ? res : S;
    }
};