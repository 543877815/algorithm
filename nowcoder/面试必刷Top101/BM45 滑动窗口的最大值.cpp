// 双端队列
// 时间复杂度：O(n)
// 空间复杂度：O(size)
class MaxQueue {
private:
    queue<int> q;
    deque<int> dq;

public:
    MaxQueue() {

    }

    int max_value() {
        if (dq.empty()) return -1;
        return dq.front();
    }

    void push_back(int value) {
        q.push(value);
        while (!dq.empty() && dq.back() < value) {
            dq.pop_back();
        }
        dq.push_back(value);
    }

    int pop_front() {
        int res = -1;
        if (!q.empty()) {
            res = q.front();
            q.pop();
        } else {
            return res;
        }
        if (res == dq.front()) dq.pop_front();
        return res;
    }
};

class Solution {
public:
    vector<int> maxInWindows(const vector<int>& nums, int size) {
        int n = nums.size();
        auto *mq = new MaxQueue();
        for (int i = 0; i < size; i++) {
            mq->push_back(nums[i]);
        }

        vector<int> res;
        for (int i = size; i < n; i++) {
            res.push_back(mq->max_value());
            mq->push_back(nums[i]);
            mq->pop_front();
        }

        res.push_back(mq->max_value());

        return res;
    }
};