// 优先队列
// 时间复杂度：O(logn) / O(n)
// 空间复杂度：O(k)
class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int k = 0;
    KthLargest(int k, vector<int>& nums) {
        int n = nums.size();
        this->k = k;
        for (int i = 0; i < n; i++) {
            pq.push(nums[i]);
            if (pq.size() > k) pq.pop();
        }
    }

    int add(int val) {
        pq.push(val);
        if (pq.size() > k) pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */