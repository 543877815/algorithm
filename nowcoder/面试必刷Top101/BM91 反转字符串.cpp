// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    /**
     * 反转字符串
     * @param str string字符串
     * @return string字符串
     */
    string solve(string str) {
        // write code here
        reverse(str.begin(), str.end());
        return str;
    }
};