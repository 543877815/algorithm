// 递归
// 时间复杂度：O(n^2)
// 空间复杂度：O(n)
class Solution {
public:
    string makeLargestSpecial(string s) {
        int n = s.size();
        if (n <= 2) return s;
        int cnt = 0, left = 0;
        vector <string> subs;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                cnt++;
            } else {
                cnt--;
                if (cnt == 0) {
                    subs.push_back("1" + makeLargestSpecial(s.substr(left + 1, i - left - 1)) + "0");
                    left = i + 1;
                }
            }
        }
        sort(subs.begin(), subs.end(), greater < string > {});
        string ans = accumulate(subs.begin(), subs.end(), ""s);
        return ans;
    }
};