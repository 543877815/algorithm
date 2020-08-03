// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    int strToInt(string str) {
        if (str.empty()) return 0;
        if (!(str[0] - '0' >= 0 && str[0] - '9' <= 0) && str[0] != '+' && str[0] != '-' && str[0] != ' ') return 0;
        int i = 0, max = pow(2, 31) - 1, min = -pow(2, 31);
        long res = 0;

        // 处理空格
        while(str[i] == ' ') i++;
        int sign = 1;

        // 正负号
        if (str[i] == '-') {
            sign = -1;
            i++;
        } else if (str[i] == '+') {
            sign = 1;
            i++;
        }

        // 循环
        while(i < str.size()) {
            if (str[i] >= '0' && str[i] <= '9') {
                res = res * 10 + sign * (str[i] - '0');
                if (res > max) return max;
                if (res < min) return min;
            } else {
                return res;
            }
            i++;
        }
        return res;
    }
};