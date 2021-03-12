// 栈
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    int minAddToMakeValid(string S) {
        int n = S.size();
        stack<int> stk;
        for (int i = 0; i < n; i++) {
            if (stk.empty()) {
                stk.push(S[i]);
            } else {
                if (stk.top() == '(' && S[i] == ')') stk.pop();
                else stk.push(S[i]);
            }
        }

        return stk.size();
    }
};