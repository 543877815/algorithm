// 一次遍历
// 时间复杂度：O(n+m)
// 空间复杂度：O(1)
class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.size();
        int m = b.size();
        int i = 0, j = 0;
        string res;
        int logit = 0;
        while (i < n && i < m) {
            int ai = a[n - 1 - i] - '0';
            int bi = b[m - 1 - i] - '0';
            int sum = ai + bi + logit;
            logit = sum / 2;
            res.push_back(sum % 2 + '0');
            i++;
        }

        while (i < n) {
            int ai = a[n - 1 - i] - '0';
            int sum = ai + logit;
            logit = sum / 2;
            res.push_back(sum % 2 + '0');
            i++;
        }

        while (i < m) {
            int bi = b[m - 1 - i] - '0';
            int sum = bi + logit;
            logit = sum / 2;
            res.push_back(sum % 2 + '0');
            i++;
        }

        if (logit) res.push_back('1');

        reverse(res.begin(), res.end());
        return res;
    }
};