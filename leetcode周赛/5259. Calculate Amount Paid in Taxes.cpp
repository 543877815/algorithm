// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    double calculateTax(vector <vector<int>> &brackets, int income) {
        double res = 0;
        int n = brackets.size();
        if (n == 0 || income == 0) return res;
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                double rate = (double) brackets[i][1] / 100;
                double money = (double) brackets[i][0];
                res += (min((double) income, money)) * rate;
            } else if (brackets[i - 1][0] < income) {
                double rate = (double) brackets[i][1] / 100;
                double money1 = (double) brackets[i - 1][0];
                double money2 = (double) brackets[i][0];
                res += rate * min((double) income - money1, money2 - money1);
            } else {
                break;
            }
        }
        return res;
    }
};