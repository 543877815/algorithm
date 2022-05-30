// 时间复杂度：O(2^n)
// 空间复杂度：O(n)
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param n int整型
     * @return string字符串vector
     */

    vector<string> res;
    void dfs(int left, int right, string& tmp) {
        if (left == 0 && right == 0) {
            res.push_back(tmp);
            return;
        }
        if (left > 0) {
            tmp.push_back('(');
            dfs(left-1, right, tmp);
            tmp.pop_back();
        }
        if (right > 0 && left < right) {
            tmp.push_back(')');
            dfs(left, right-1, tmp);
            tmp.pop_back();
        }
        return;
    }

    vector<string> generateParenthesis(int n) {
        // write code here
        string tmp = "";
        dfs(n, n, tmp);
        return res;
    }
};