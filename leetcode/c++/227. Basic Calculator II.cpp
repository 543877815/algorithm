// 栈
// 时间复杂度：O(n)
// 空见复杂度：O(n)
class Solution {
public:
    int calculate(string s) {
        stack<int> ops;
        stack<char> signs;
        int n = s.size();
        bool exec = false;
        int i = 0;
        while (i < n) {
            if (s[i] >= '0' && s[i] <= '9') {
                long num = 0;
                while (i < n && s[i] >= '0' && s[i] <= '9') {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }

                if (exec) {
                    int lastNum = ops.top();
                    ops.pop();
                    if (signs.top() == '*') {
                        ops.push(lastNum * num);
                    } else if (signs.top() == '/') {
                        ops.push(lastNum / num);
                    }
                    signs.pop();
                    exec = false;
                } else {
                    ops.push(num);
                }

            } else if (s[i] == '+') {
                signs.push(s[i]);
                exec = false;
                i++;
            } else if (s[i] == '-') {
                signs.push(s[i]);
                exec = false;
                i++;
            } else if (s[i] == '/') {
                signs.push(s[i]);
                exec = true;
                i++;
            } else if (s[i] == '*') {
                signs.push(s[i]);
                exec = true;
                i++;
            } else if (s[i] == ' ') {
                i++;
            }
        }

        int res = 0;
        while (!signs.empty()) {
            if (signs.top() == '+') {
                res += ops.top();
            } else if (signs.top() == '-') {
                res -= ops.top();
            }
            ops.pop();
            signs.pop();
        }
        if (!ops.empty()) {
            res += ops.top();
            ops.pop();
        }
        return res;
    }
};

class Solution {
public:
    int calculate(string s) {
        vector<int> stk;
        char preSign = '+';
        int num = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
            }
            if (!isdigit(s[i]) && s[i] != ' ' || i == n - 1) {
                switch(preSign) {
                    case '+':
                        stk.push_back(num);
                        break;
                    case '-':
                        stk.push_back(-num);
                        break;
                    case '*':
                        stk.back() *= num;
                        break;
                    default:
                        stk.back() /= num;
                }
                preSign = s[i];
                num = 0;
            }
        }
        return accumulate(stk.begin(), stk.end(), 0);
    }
};