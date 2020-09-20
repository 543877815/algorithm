// 时间复杂度：O(digit)
// 空间复杂度：O(n)
class Solution {
public:
    int countDigitOne(int n) {

        // 计算i+1位有多少个1
        vector<int> record;
        record.push_back(0);
        for (int i = 0; i < 9; i++) {
            record.push_back((int) pow(10.0, i) * (i + 1));
        }

        // 计算位数
        int digit = 0, tmp_n = n;
        while (tmp_n != 0) {
            tmp_n /= 10;
            digit++;
        }

        if (digit == 0) return record[0];

        int res = 0;
        int left_pow, right_pow, left_remain, right_remain, ith_num;
        for (int i = 0; i < digit; i++) {
            left_pow = (int) pow(10, digit - (i + 2));
            right_pow = (int) pow(10, i);
            left_remain = n / 10 / (int) pow(10, i);
            right_remain = n % (int) pow(10, i);
            ith_num = n / right_pow % 10;
            if (ith_num > 1) {
                res += (left_remain - left_pow + 1) * right_pow;
            } else if (ith_num == 1) {
                if (right_remain == 0) {
                    res += left_remain - left_pow + 1;
                } else {
                    res += (left_remain - left_pow) * right_pow + (right_remain + 1);
                }
            } else {
                res += ((left_remain - left_pow) * right_pow);
            }
        }
        return res + record[digit - 1];
    }
};
