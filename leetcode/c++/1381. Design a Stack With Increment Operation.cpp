// 栈
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class CustomStack {
public:
    stack<int> stk;
    int maxSize = 0;

    CustomStack(int maxSize) {
        this->maxSize = maxSize;
    }

    void push(int x) {
        if (stk.size() < maxSize) stk.push(x);
    }

    int pop() {
        if (!stk.empty()) {
            int top = stk.top();
            stk.pop();
            return top;
        } else return -1;
    }

    void increment(int k, int val) {
        stack<int> tmp;
        while (!stk.empty()) {
            tmp.push(stk.top());
            stk.pop();
        }
        int i = 0;
        while (i < k && !tmp.empty()) {
            stk.push(tmp.top() + val);
            tmp.pop();
            i++;
        }
        while (!tmp.empty()) {
            stk.push(tmp.top());
            tmp.pop();
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */

// 优化
// 时间复杂度：O(1)
// 空间复杂度：O(n)
class CustomStack {
public:
    vector<int> stk, add;
    int top = -1;
    CustomStack(int maxSize) {
        stk.resize(maxSize);
        add.resize(maxSize);
        top = -1;
    }

    void push(int x) {
        if (top != stk.size() - 1) {
            top++;
            stk[top] = x;
        }
    }

    int pop() {
        if (top == -1) return -1;
        int res = stk[top] + add[top];
        if (top != 0) add[top - 1] += add[top];
        add[top] = 0;
        top--;
        return res;
    }

    void increment(int k, int val) {
        int lim = min(k - 1, top);
        if (lim >= 0) {
            add[lim] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */