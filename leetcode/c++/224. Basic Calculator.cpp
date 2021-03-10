// 栈
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    stack <string> sk;

    void exec() {
        if (sk.size() <= 1) return;
        int a = 0;
        while (!sk.empty() && sk.top() != "(" && sk.top() != ")" && sk.top() != "+" && sk.top() != "-") {
            a = a * 10 + stoi(sk.top());
            sk.pop();
        }
        if (sk.empty()) {
            sk.push(to_string(a));
            return;
        }
        string opera = sk.top();
        sk.pop();

        int b = 0;
        while (!sk.empty() && sk.top() != "(" && sk.top() != ")" && sk.top() != "+" && sk.top() != "-") {
            b = b * 10 + stoi(sk.top());
            sk.pop();
        }
        if (opera == "+") {
            a = a + b;
        } else if (opera == "-") {
            a = a - b;
        } else {
            sk.push(to_string(a));
            return;
        }
        if (!sk.empty()) {
            if (sk.top() == ")") {
                sk.pop();
                sk.push(to_string(a));
            } else {
                sk.push(to_string(a));
                exec();
            }
        } else {
            sk.push(to_string(a));
        }
    }

    int calculate(string s) {
        int n = s.size();
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '(') exec();
            else if (s[i] != ' ') {
                sk.push(string(1, s[i]));
            }
        }

        while (sk.size() > 1) exec();

        return stoi(sk.top());
    }
};


class Solution {
public:
    int calculate(string s) {
        stack<int> ops;
        ops.push(1);
        int sign = 1;

        int ret = 0;
        int n = s.length();
        int i = 0;
        while (i < n) {
            if (s[i] == ' ') {
                i++;
            } else if (s[i] == '+') {
                sign = ops.top();
                i++;
            } else if (s[i] == '-') {
                sign = -ops.top();
                i++;
            } else if (s[i] == '(') {
                ops.push(sign);
                i++;
            } else if (s[i] == ')') {
                ops.pop();
                i++;
            } else {
                long num = 0;
                while (i < n && s[i] >= '0' && s[i] <= '9') {
                    num = num * 10 + s[i] - '0';
                    i++;
                }
                ret += sign * num;
            }
        }
        return ret;
    }
};
