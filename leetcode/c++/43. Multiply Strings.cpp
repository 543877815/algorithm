// 时间复杂度：O(nm)
// 空间复杂度：O(n+m)
class Solution {
public:
    string multiply(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        string res = "";
        int count = 0;
        for (int i = 0; i < num1.size(); i++) {
            for (int j = 0; j < num2.size(); j++) {
                int a = num1[i] - '0';
                int b = num2[j] - '0';
                int result = a * b;
                int index = i + j;
                if (result == 0) res += '0';
                while (result > 0) {
                    int digit = result % 10;
                    if (res.size() == index) {
                        res += to_string(digit);
                    } else {
                        int tmp = res[index] - '0';
                        res[index] = ((tmp + digit) % 10) + '0';
                        result += tmp;
                    }
                    index++;
                    result /= 10;
                }

            }
        }
        reverse(res.begin(), res.end());

        // 去除多余的零
        int zeroCount = 0;
        for (int i = 0; i < res.size(); i++) {
            if (res[i] == '0') zeroCount++;
            else break;
        }
        if (zeroCount > 0) res = res.substr(zeroCount);
        return res.size() == 0 ? "0" : res;
    }
};
