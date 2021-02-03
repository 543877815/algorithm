// 滑动窗口 大小顶堆 延迟删除
// 时间复杂度：O(nlogn)
// 空间复杂度：O(n)
class DualHeap {
private:
    priority_queue<int, vector<int>, less<int>> min_heap;
    priority_queue<int, vector<int>, greater<int>> max_heap;
    unordered_map<int, int> delayed;
    int k;;
    int smallSize, largeSize;

public:
    DualHeap(int _k) : k(_k), smallSize(0), largeSize(0) {}

    void insert(int num) {
        if (min_heap.empty() || num <= min_heap.top()) {
            min_heap.push(num);
            smallSize++;
        } else {
            max_heap.push(num);
            largeSize++;
        }
        makeBalance();
    }

    template<typename T>
    void prune(T &heap) {
        while (!heap.empty()) {
            int num = heap.top();
            if (delayed.count(num)) {
                delayed[num]--;
                if (!delayed[num]) {
                    delayed.erase(num);
                }
                heap.pop();
            } else break;
        }
    }

    void makeBalance() {
        // 如果min_heap比max_heap多2
        if (smallSize > largeSize + 1) {
            max_heap.push(min_heap.top());
            min_heap.pop();
            smallSize--;
            largeSize++;
            prune(min_heap);
            // 如果max_heap比min_heap多1
        } else if (largeSize > smallSize) {
            min_heap.push(max_heap.top());
            smallSize++;
            largeSize--;
            max_heap.pop();
            prune(max_heap);
        }
    }

    void erase(int num) {
        delayed[num]++;
        if (num <= min_heap.top()) {
            smallSize--;
            if (num == min_heap.top()) {
                prune(min_heap);
            }
        } else {
            largeSize--;
            if (num == max_heap.top()) {
                prune(max_heap);
            }
        }
        makeBalance();
    }

    double getMedian() {
        return k & 1 ? min_heap.top() : ((double) min_heap.top() + max_heap.top()) / 2;
    }
};

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int> &nums, int k) {
        DualHeap dh(k);
        for (int i = 0; i < k; i++) {
            dh.insert(nums[i]);
        }
        vector<double> ans = {dh.getMedian()};
        for (int i = k; i < nums.size(); i++) {
            dh.insert(nums[i]);
            dh.erase(nums[i - k]);
            ans.push_back(dh.getMedian());
        }
        return ans;
    }
};