// 栈
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 返回表达式的值
     * @param s string字符串 待计算的表达式
     * @return int整型
     */
    stack<int> nums;
    stack<char> charas;

    int getNum(string &s, int &i) {
        int num = 0;
        while (isdigit(s[i])) {
            num = num * 10 + s[i] - '0';
            i++;
        }
        return num;
    }

    void exec() {
        int num1 = nums.top();
        nums.pop();
        int num2 = nums.top();
        nums.pop();
        char chara = charas.top();
        charas.pop();
        if (chara == '+') {
            num1 += num2;
        } else if (chara == '*') {
            num1 *= num2;
        }
        nums.push(num1);
    }

    void solve(string &s, int &i) {
        string opera = "+-*(";
        int n = s.size();
        int result;
        bool pos = true;
        while (i < n) {
            if (isdigit(s[i])) {
                int num = getNum(s, i);
                if (pos) nums.push(num);
                else nums.push(-num);
                if (!charas.empty() && charas.top() == '*') exec();
                pos = true;
            } else {
                if (s[i] == '+') {
                    pos = true;
                    charas.push(s[i]);
                    i++;
                } else if (s[i] == '-') {
                    pos = false;
                    charas.push('+');
                    i++;
                } else if (s[i] == '*') {
                    charas.push(s[i]);
                    i++;
                } else if (s[i] == '(') {
                    charas.push(s[i]);
                    i++;
                    solve(s, i);
                    if (!pos) nums.top() = -nums.top();
                    pos = true;
                } else if (s[i] == ')') {
                    while (!charas.empty() && charas.top() != '(' && (int) nums.size() >= 2) {
                        exec();
                    }
                    charas.pop();
                    i++;
                    return;
                }
            }
        }
        while (!charas.empty() && (int) nums.size() >= 2) {
            exec();
        }
    }

    int solve(string s) {
        // write code here
        int i = 0;
        solve(s, i);

        return nums.top();
    }
};