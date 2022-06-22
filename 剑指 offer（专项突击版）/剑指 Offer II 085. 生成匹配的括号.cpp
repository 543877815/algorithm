// 时间复杂度：O(2^n)
// 空间复杂度：O(n)

class Solution {
public:
    vector <string> res;

    void backtrack(int left, int right, string &tmp) {
        if (left == 0 && right == 0) {
            res.push_back(tmp);
        }

        if (left > 0) {
            tmp.push_back('(');
            backtrack(left - 1, right, tmp);
            tmp.pop_back();
        }

        if (right > left && right > 0) {
            tmp.push_back(')');
            backtrack(left, right - 1, tmp);
            tmp.pop_back();
        }
    }

    vector <string> generateParenthesis(int n) {
        string tmp = "";
        backtrack(n, n, tmp);

        return res;
    }
};