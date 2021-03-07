// 栈
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    string removeOuterParentheses(string S) {
        int n = S.size();
        stack<int> sk;
        bool isDelete = false;
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (S[i] == '(') {
                if (isDelete || count != 0) {
                    sk.push(S[i]);
                    count++;
                } else isDelete = true;
            } else if (S[i] == ')') {
                if (!isDelete || count != 0) {
                    sk.push(S[i]);
                    count--;
                } else isDelete = false;
            }
        }

        string res;
        while (!sk.empty()) {
            res += sk.top();
            sk.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};