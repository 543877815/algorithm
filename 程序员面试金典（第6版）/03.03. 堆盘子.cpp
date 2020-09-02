class StackOfPlates {
private:
    int maxSize;
    vector <stack<int>> stacks;

public:
    StackOfPlates(int cap) {
        maxSize = cap;
    }

    void push(int val) {
        if (maxSize == 0) return;
        if (stacks.size() == 0) {
            stack<int> s;
            s.push(val);
            stacks.push_back(s);
        } else {
            stack<int> *s = &stacks.back();
            if (s->size() >= maxSize) {
                stack<int> tmp;
                tmp.push(val);
                stacks.push_back(tmp);
            } else {
                stacks.back().push(val);
            }
        }
    }

    int pop() {
        if (stacks.empty()) return -1;
        stack<int> *s = &stacks.back();
        int num = s->top();
        s->pop();
        if (s->empty()) stacks.pop_back();
        return num;
    }

    int popAt(int index) {
        if (stacks.empty() || stacks.size() <= index) return -1;
        stack<int> *s = &stacks[index];
        if (s->empty()) return -1;
        int num = s->top();
        s->pop();
        if (s->size() == 0) stacks.erase(remove(stacks.begin(), stacks.end(), *s), stacks.end());
        return num;
    }
};