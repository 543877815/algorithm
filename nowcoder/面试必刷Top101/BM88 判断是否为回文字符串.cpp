// 双指针
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * @param str string字符串 待判断的字符串
     * @return bool布尔型
     */
    bool judge(string str) {
        // write code here
        int n = str.size();
        if (n == 0) return true;
        int i = 0, j = n - 1;
        while (i <= j) {
            if (str[i++] != str[j--]) return false;
        }
        return true;
    }
};