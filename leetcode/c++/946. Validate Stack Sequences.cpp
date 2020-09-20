// 使用辅助栈
// 时间复杂度：O(n)
// 空间复杂度：O(n)

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if (pushed.size() != popped.size()) return false;
        stack<int> q;
        int push_index = 0;
        int pop_index = 0;
        while(pop_index < popped.size()) {
            while(q.empty() || q.top() != popped[pop_index]) {
                if (push_index == pushed.size()) break;
                q.push(pushed[push_index++]);
            }
            if (q.top() != popped[pop_index]) break;
            q.pop();
            pop_index++;
        }
        return q.empty() && pop_index == popped.size();
    }
};