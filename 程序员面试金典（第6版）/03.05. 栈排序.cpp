// 辅助栈暂存数据
class SortedStack {
private:
    stack<int> s;
    stack<int> as;
public:
    SortedStack() {

    }

    void push(int val) {
        if (s.empty()) {
            s.push(val);
        } else {
            if (s.top() >= val) {
                s.push(val);
            } else {
                while (!s.empty() && s.top() < val) {
                    as.push(s.top());
                    s.pop();
                }
                s.push(val);
                while (!as.empty()) {
                    s.push(as.top());
                    as.pop();
                }
            }
        }
    }

    void pop() {
        if (!s.empty()) s.pop();
    }

    int peek() {
        return s.empty() ? -1 : s.top();
    }

    bool isEmpty() {
        return s.empty();
    }
};


// 辅助栈升序
class SortedStack {
private:
    stack<int> s1;
    stack<int> s2;

public:
    SortedStack() {

    }

    void push(int val) {
        while (!s2.empty() && s2.top() > val) {
            s1.push(s2.top());
            s2.pop();
        }
        while (!s1.empty() && s1.top() < val) {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(val);
    }

    void pop() {
        while (!s2.empty()) { // 清空辅助栈
            s1.push(s2.top());
            s2.pop();
        }
        if (!s1.empty()) s1.pop();
    }

    int peek() {
        while (!s2.empty()) { // 清空辅助栈
            s1.push(s2.top());
            s2.pop();
        }
        return s1.empty() ? -1 : s1.top();
    }

    bool isEmpty() {
        return s1.empty() && s2.empty();
    }
};

