// 栈
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> sk;
        int n = ops.size();
        for (int i = 0; i < n; i++) {
            if (ops[i] == "C") {
                sk.pop();
            } else if (ops[i] == "D") {
                sk.push(sk.top() * 2);
            } else if (ops[i] == "+") {
                int a = sk.top();
                sk.pop();
                int b = sk.top();
                sk.push(a);
                sk.push(a+b);
            } else {
                sk.push(stoi(ops[i]));
            }
        }

        int res = 0;
        while(!sk.empty()) {
            res += sk.top();
            sk.pop();
        }

        return res;
    }
};