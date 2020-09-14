// 回溯算法
// 时间复杂度：O(2^n)
// 空间复杂度：O(2n)
class Solution {
public:
    vector <string> res;

    void DFS(string &str, int left, int right) {
        if (left == 0 && right == 0) {
            res.push_back(str);
            return;
        }
        str += '(';
        if (left > 0) DFS(str, left - 1, right);
        str.pop_back();
        str += ')';
        if (left < right) DFS(str, left, right - 1);
        str.pop_back();
    }

    vector <string> generateParenthesis(int n) {
        string str;
        DFS(str, n, n);
        return res;
    }
};