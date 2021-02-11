// 堆 优先队列
// 时间复杂度：O(nlogk)
// 空间复杂度：O(nlogk)
class KthLargest {
public:
    priority_queue<int> pq;
    int k;

    KthLargest(int k, vector<int> &nums) {
        this->k = k;
        for (int i = 0; i < nums.size(); i++) {
            add(nums[i]);
        }
    }

    int add(int val) {
        if (pq.size() < k) {
            pq.push(val);
        } else if (pq.top() < val) {
            pq.pop();
            pq.push(val);
        }

        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */