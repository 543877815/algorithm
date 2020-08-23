// 时间复杂度：O(n+m)
// 空间复杂度：O(n+m)
class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.size();
        if (m == 0) return b;
        int n = b.size();
        if (n == 0) return a;

        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        int i = 0, j = 0, count = 0;
        while (i < m && j < n) {
            int a_n = a[i] - '0';
            int b_n = b[i] - '0';
            int sum = a_n + b_n + count;
            a[i] = (sum % 2) + '0';
            count = sum / 2;
            i++;
            j++;
        }

        while (i < m) {
            int a_n = a[i] - '0';
            int sum = a_n + count;
            a[i] = (sum % 2) + '0';
            count = sum / 2;
            i++;
        }

        while (j < n) {
            int b_n = b[j] - '0';
            int sum = b_n + count;
            a += (sum % 2) + '0';
            count = sum / 2;
            j++;
        }

        if (count == 1) a += count + '0';

        reverse(a.begin(), a.end());
        return a;
    }
};