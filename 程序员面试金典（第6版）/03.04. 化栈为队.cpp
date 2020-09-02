class MyQueue {
private:
    stack<int> q_in;
    stack<int> q_out;

public:
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        q_in.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (empty()) return -1;
        if (!q_out.empty()) {
            int num = q_out.top();
            q_out.pop();
            return num;
        } else {
            while (!q_in.empty()) {
                int num = q_in.top();
                q_in.pop();
                q_out.push(num);
            }
            return pop();
        }
    }

    /** Get the front element. */
    int peek() {
        if (empty()) return -1;
        if (!q_out.empty()) {
            return q_out.top();
        } else {
            while (!q_in.empty()) {
                int num = q_in.top();
                q_in.pop();
                q_out.push(num);
            }
            return peek();
        }
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return q_in.empty() && q_out.empty();
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