// 使用辅助栈
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class MinStack {

private:
    stack<int> s;
    stack<int> min_stack;

public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        s.push(x);

        if (min_stack.size() == 0 || x < min_stack.top()) {
            min_stack.push(x);
        } else {
            min_stack.push(min_stack.top());
        }

    }

    void pop() {
        assert(s.size() > 0 && min_stack.size() > 0);

        s.pop();
        min_stack.pop();
    }

    int top() {
        return s.top();
    }

    int min() {
        return min_stack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */