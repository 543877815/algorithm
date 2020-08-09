// 空间复杂度：O(n)
// 时间复杂度：O(1)
class MaxQueue {
private:
    queue<int> q;
    deque<int> dq;
public:
    MaxQueue() {

    }

    int max_value() {
        if (dq.empty()) return -1;
        else return dq.front();
    }

    void push_back(int value) {
        q.push(value);
        while (!dq.empty() && value >= dq.back())
            dq.pop_back();
        dq.push_back(value);
    }

    int pop_front() {
        if (q.empty()) return -1;
        int temp = q.front();
        q.pop();
        if (temp == dq.front())
            dq.pop_front();
        return temp;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */