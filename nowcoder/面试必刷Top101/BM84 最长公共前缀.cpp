class Solution {
public:
    /**
     *
     * @param strs string字符串vector
     * @return string字符串
     */
    string longestCommonPrefix(vector<string>& strs) {
        // write code here
        int n = strs.size();
        int num = 0;
        int res = 0;
        if (n == 0) return "";
        if (n == 1) return strs[0];
        for (int i = 0; i < strs[0].size(); i++) {
            bool same = true;
            for (int j = 1; j < n; j++) {
                if (strs[j - 1][i] != strs[j][i]) {
                    same = false;
                    num = 0;
                    break;
                }
            }
            if (same) {
                num++;
                res = max(res, num);
            }
        }
        return strs[0].substr(0, res);
    }
};