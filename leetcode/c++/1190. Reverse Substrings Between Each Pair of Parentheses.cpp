// 时间复杂度：O(n^2)
// 空间复杂度：O(1)
// 单调栈
class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();
        int index = 0;
        stack<int> sk;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') sk.push(i);
             else if (s[i] == ')') {
                int top = sk.top();
                sk.pop();
                reverse(s.begin()+top, s.begin()+i);
            }
        }
        string res;
        for (int i = 0; i < n; i++) {
            if (s[i] != '(' && s[i] != ')') {
                res.push_back(s[i]);
            }
        }
        return res;
    }
};

// 时间复杂度：O(n^2)
// 空间复杂度：O(1)
// 单调栈
class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> stk;
        string str;
        for (auto &ch : s) {
            if (ch == '(') {
                stk.push(str);
                str = "";
            } else if (ch == ')') {
                reverse(str.begin(), str.end());
                str = stk.top() + str;
                stk.pop();
            } else {
                str.push_back(ch);
            }
        }
        return str;
    }
};


// 时间复杂度：O(n)
// 空间复杂度：O(n)
// 将翻转看成逆序遍历
// (  u (  l  o  v  e )  i )  step  res
// 9 -1 7 -1 -1 -1 -1 2 -1 0
class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();
        vector<int> pair(n);
        stack<int> stk;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                stk.push(i);
            } else if (s[i] == ')') {
                int j = stk.top();
                stk.pop();
                pair[i] = j, pair[j] = i;
            }
        }
        string res;
        int index = 0, step = 1;
        while (index < n) {
            if (s[index] == '(' || s[index] == ')') {
                index = pair[index];
                step = -step;
            } else {
                res.push_back(s[index]);
            }
            index += step;
        }
        return res;
    }
};