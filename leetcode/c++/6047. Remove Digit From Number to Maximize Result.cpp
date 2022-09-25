// 遍历
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    string removeDigit(string number, char digit) {
        int n = number.size();
        bool removed = false;
        string res;
        for (int i = 0; i < n; i++) {
            if (number[i] == digit && !removed) {
                if (i < n + 1 && number[i] < number[i + 1]) {
                    removed = true;
                    continue;
                }
            }

            res += number[i];
        }

        if (!removed) {
            res = "";
            for (int i = n - 1; i >= 0; i--) {
                if (number[i] == digit && !removed) {
                    removed = true;
                    continue;
                }

                res += number[i];
            }
            reverse(res.begin(), res.end());
        }

        return res;
    }
};