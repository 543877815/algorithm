// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
private:
    int index;

    // 去除空格
    void strip(string &s) {
        while (index != s.size() && s[index] == ' ') {
            index++;
        }
    }

    // 扫描整数
    bool scanInteger(string &s) {
        if (s[index] == '+' || s[index] == '-') index++;
        return scanUnsignedInteger(s);
    }

    // 扫描无符号整数
    bool scanUnsignedInteger(string &s) {
        int before = index;
        while (index != s.size() && s[index] >= '0' && s[index] <= '9')
            index++;
        return index > before;
    }

public:
    bool isNumber(string s) {
        index = 0;
        if (s.size() == 0) return false;

        // 先去空格
        strip(s);

        bool numeric = scanInteger(s);

        // 如果出现'.',则接下来是数字的小数部分
        if (s[index] == '.') {
            index++;
            // 下面一行代码用||的原因：
            // 1. 小数可以没有整数部分，如.123等于0.123;
            // 2. 小数点后面可以没有数字, 如233等于233.0
            // 3. 当然, 小数点前面和后面可以都有数字, 如233.666
            numeric = scanUnsignedInteger(s) || numeric;
        }

        // 如果出现'e'或者'E', 则接下来是数字的指数部分
        if (s[index] == 'e' || s[index] == 'E') {
            index++;
            numeric = numeric && scanInteger(s);
        }

        strip(s);

        return numeric && index == s.size();
    }
};