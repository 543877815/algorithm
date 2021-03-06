// 双栈
// 时间复杂度：O(1)
// 空间复杂度：O(n)
class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> stack1, stack2;

    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        stack1.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        if (stack2.empty()) {
            return -1;
        } else {
            int res = stack2.top();
            stack2.pop();
            return res;
        }
    }

    /** Get the front element. */
    int peek() {
        if (!stack2.empty()) {
            return stack2.top();
        } else {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }

        if (stack2.empty()) {
            return -1;
        } else {
            return stack2.top();
        }
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return stack1.size() == 0 && stack2.size() == 0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */