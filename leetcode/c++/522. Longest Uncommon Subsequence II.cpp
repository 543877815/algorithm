// 枚举
// 时间复杂度: O(l n^2)
// 空间复杂度：O(1)
class Solution {
public:
    bool isSubSeq(const string &s, const string &t) {
        int pt_s = 0, pt_t = 0;
        while (pt_s < s.size() && pt_t < t.size()) {
            if (s[pt_s] == t[pt_t]) pt_s++;
            ++pt_t;
        }
        return pt_s == s.size();
    }

    int findLUSlength(vector <string> &strs) {
        int n = strs.size();
        int ans = -1;
        for (int i = 0; i < n; ++i) {
            bool check = true;
            for (int j = 0; j < n; ++j) {
                if (i != j && isSubSeq(strs[i], strs[j])) {
                    check = false;
                    break;
                }
            }
            if (check) {
                ans = max(ans, static_cast<int>(strs[i].size()));
            }
        }
        return ans;
    }
};

\