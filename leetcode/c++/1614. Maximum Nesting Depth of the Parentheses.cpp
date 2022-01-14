747. Largest Number At Least Twice of Others// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();
        int res = 0;
        int num = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                num++;
                res = max(res, num);
            }
            if (s[i] == ')' && num > 0) {
                num--;
            }
        }


        return res;
    }
};