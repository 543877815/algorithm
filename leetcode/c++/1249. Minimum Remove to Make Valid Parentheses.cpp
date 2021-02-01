// 栈
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();
        stack<int> parenthese;
        vector<bool> remain(n, true);
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                parenthese.push(i);
            } else if (s[i] == ')') {
                if (parenthese.empty()) {
                    remain[i] = false;
                } else {
                    parenthese.pop();
                }
            }
        }
        while (!parenthese.empty()) {
            int index = parenthese.top();
            parenthese.pop();
            remain[index] = false;
        }
        string res;
        for (int i = 0; i < n; i++) {
            if (remain[i]) res.push_back(s[i]);
        }
        return res;
    }
};