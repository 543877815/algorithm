// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    /**
     *
     * @param s string字符串
     * @return bool布尔型
     */
    stack<int> sk;

    bool isValid(string s) {
        // write code here
        int n = s.size();
        if (n % 2 == 1) return false;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                sk.push(s[i]);
            }
            if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
                if (sk.empty()) return false;
                if (s[i] == ')') {
                    if (sk.top() != '(') return false;
                    else sk.pop();
                }
                if (s[i] == ']') {
                    if (sk.top() != '[') return false;
                    else sk.pop();
                }
                if (s[i] == '}') {
                    if (sk.top() != '{') return false;
                    else sk.pop();
                }
            }
        }

        return sk.empty();
    }
};