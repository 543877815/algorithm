// 分治算法
// 时间复杂度：O(2^n)
// 空间复杂度：O(2^n)
class Solution {
public:
    int parseInt(string &str) {
        int num = 0;
        for (int i = 0; i < str.size(); i++) {
            num = num * 10 + (str[i] - '0');
        }

        return num;
    }

    unordered_map <string, vector<int>> memo;

    vector<int> diffWaysToCompute(string expression) {
        if (memo.count(expression)) {
            return memo[expression];
        }

        vector<int> res;
        int n = expression.size();
        for (int i = 0; i < n; i++) {
            char c = expression[i];
            if (c == '-' || c == '+' || c == '*') {
                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                vector<int> right = diffWaysToCompute(expression.substr(i + 1));

                for (int a: left) {
                    for (int b: right) {
                        if (c == '+') {
                            res.push_back(a + b);
                        } else if (c == '-') {
                            res.push_back(a - b);
                        } else if (c == '*') {
                            res.push_back(a * b);
                        }
                    }
                }
            }

        }

        if (res.empty()) {
            res.push_back(parseInt(expression));
        }

        memo[expression] = res;
        return res;
    }
};