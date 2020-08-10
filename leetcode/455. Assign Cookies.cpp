// 贪心算法
// 时间复杂度：O(nlogn+n)
// 空间复杂度：O(1)
class Solution {
public:
    int findContentChildren(vector<int> &g, vector<int> &s) {
        int n = g.size();
        int m = s.size();
        sort(g.begin(), g.end(), greater<int>());
        sort(s.begin(), s.end(), greater<int>());

        int si = 0, gi = 0;
        int res = 0;

        while (gi < g.size() && si < s.size()) {
            if (s[si] >= g[gi]) {
                res++;
                si++;
                gi++;
            } else {
                gi++;
            }
        }

        return res;
    }
};