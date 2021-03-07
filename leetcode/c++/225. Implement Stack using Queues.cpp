// 时间复杂度：O(1)
// 空间复杂度：O(n)
class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int> queue1;
    queue<int> queue2;
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        if (queue1.empty()) {
            queue1.push(x);
            while (!queue2.empty()) {
                queue1.push(queue2.front());
                queue2.pop();
            }
        } else if (queue2.empty()) {
            queue2.push(x);
            while (!queue1.empty()) {
                queue2.push(queue1.front());
                queue1.pop();
            }
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if (!queue1.empty()) {
            int res = queue1.front();
            queue1.pop();
            return res;
        } else if (!queue2.empty()) {
            int res = queue2.front();
            queue2.pop();
            return res;
        } else {
            return -1;
        }
    }

    /** Get the top element. */
    int top() {
        if (!queue1.empty()) return queue1.front();
        else if (!queue2.empty()) return queue2.front();
        else return -1;
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return queue1.empty() && queue2.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */