// 时间复杂度：O(n+m)
// 空间复杂度：O(1)
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 计算两个数之和
     * @param s string字符串 表示第一个整数
     * @param t string字符串 表示第二个整数
     * @return string字符串
     */
    string solve(string s, string t) {
        // write code here
        int i = s.size() - 1, j = t.size() - 1;
        int digit = 0;
        string res;
        while (i >= 0 && j >= 0) {
            int num = (s[i] - '0') + (t[j] - '0') + digit;
            digit = num / 10;
            num = num % 10;
            res = to_string(num) + res;
            i--;
            j--;
        }

        while (i >= 0) {
            int num = (s[i] - '0') + digit;
            digit = num / 10;
            num = num % 10;
            res = to_string(num) + res;
            i--;
        }

        while (j >= 0) {
            int num = (t[j] - '0') + digit;
            digit = num / 10;
            num = num % 10;
            res = to_string(num) + res;
            j--;
        }

        if (digit) res = to_string(digit) + res;

        return res;

    }
};