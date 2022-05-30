// 时间复杂度：O(1)
// 空间复杂度：O(n)
// 单调栈
class Solution {
public:
    stack<int> sk1;
    stack<int> sk2;
    void push(int value) {
        sk1.push(value);
        if (sk2.empty() || sk2.top() >= value) {
            sk2.push(value);
        }
    }
    void pop() {
        if (!sk1.empty() && !sk2.empty() && sk1.top() == sk2.top()) {
            sk2.pop();
        }
        if (!sk1.empty()) sk1.pop();
    }
    int top() {
        return sk1.top();
    }
    int min() {
        return sk2.top();
    }
};