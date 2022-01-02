// 队列
// 时间复杂度：O(1)
// 空间复杂度：O(size)
class MovingAverage {
public:
    /** Initialize your data structure here. */
    queue<int> q;
    int size;
    double sum = 0;
    MovingAverage(int size) {
        this->size = size;
    }

    double next(int val) {
        q.push(val);
        sum += val;
        if (q.size() > size) {
            sum -= q.front();
            q.pop();
        }
        return sum / q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */