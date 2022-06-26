// 回溯
// 时间复杂度：O(n!)
// 空间复杂度：o(n!)

class Solution {
public:
    vector <string> res;

    bool isValid(string &s) {
        if ((s.size() > 1 && s[0] == '0') || s.size() > 3)
            return false;
        return stoi(s) < 256;
    }

    void backtrack(string &s, vector <string> curr, int idx) {
        int n = s.size();
        if (curr.size() == 4) {
            if (n == idx) res.push_back(curr[0] + "." + curr[1] + "." + curr[2] + "." + curr[3]);
            return;
        }

        int i = 1;
        while (i <= 3 && idx + i - 1 < n) {
            string temp = s.substr(idx, i);
            if (isValid(temp)) {
                curr.push_back(temp);
                backtrack(s, curr, idx + i);
                curr.pop_back();

                i++;
            } else break;
        }

    }

    vector <string> restoreIpAddresses(string s) {
        // write code here
        vector <string> curr;
        backtrack(s, curr, 0);
        return res;
    }
};