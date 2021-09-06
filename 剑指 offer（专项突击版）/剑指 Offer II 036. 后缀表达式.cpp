// 逆波兰表达式
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    int evalRPN(vector <string> &tokens) {
        int n = tokens.size();
        stack<int> num_sk;
        for (int i = 0; i < n; i++) {
            if (tokens[i].size() == 1 &&
                (tokens[i][0] == '+' || tokens[i][0] == '-' || tokens[i][0] == '*' || tokens[i][0] == '/')) {
                int b = num_sk.top();
                num_sk.pop();
                int a = num_sk.top();
                num_sk.pop();
                if (tokens[i][0] == '+') {
                    num_sk.push(a + b);
                } else if (tokens[i][0] == '-') {
                    num_sk.push(a - b);
                } else if (tokens[i][0] == '*') {
                    num_sk.push(a * b);
                } else if (tokens[i][0] == '/') {
                    num_sk.push(a / b);
                }
            } else {
                int num = 0;
                bool sign = true;
                for (int j = 0; j < tokens[i].size(); j++) {
                    if (tokens[i][j] == '-') sign = false;
                    else {
                        num = num * 10 + tokens[i][j] - '0';
                    }
                }
                num_sk.push(sign ? num : -num);
            }
        }
        return num_sk.top();
    }
};