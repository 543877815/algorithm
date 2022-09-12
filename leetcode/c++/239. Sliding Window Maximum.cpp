// 时间复杂度：O(n)
// 空间复杂度：O(k)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        if (k == 1) return nums;
        vector<int> res;
        if (k == 0) return res;
        deque<int> dq;

        for (int i = 0; i < k; i++) {
            while (!dq.empty() && nums[i] >= nums[dq.back()])
                dq.pop_back();
            dq.push_back(i);
        }

        for (int i = k; i < nums.size(); i++) {
            res.push_back(nums[dq.front()]);
            while (!dq.empty() && nums[i] >= nums[dq.back()])
                dq.pop_back();
            if (!dq.empty() && dq.front() <= i - k)
                dq.pop_front();
            dq.push_back(i);
        }
        res.push_back(nums[dq.front()]);

        return res;
    }
};

// 优先队列
// 时间复杂度：O(nlogn)
// 空间复杂度：O(n)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        int n = nums.size();
        priority_queue <pair<int, int>> pq;
        vector<int> res;
        for (int i = 0; i < k; i++) {
            pq.push(make_pair(nums[i], i));
        }
        res.push_back(pq.top().first);
        for (int i = k; i < n; i++) {
            pq.push(make_pair(nums[i], i));
            while (pq.top().second <= i - k) {
                pq.pop();
            }
            res.push_back(pq.top().first);
        }
        return res;
    }
};

// 线段树
// 时间复杂度：O(nlogn)
// 空间复杂度：O(n)
class Solution {
private:
    vector<int> segmentTree;
    int n;

    void build(int node, int left, int right, vector<int> &nums) {
        if (left == right) {
            segmentTree[node] = nums[left];
            return;
        }
        int mid = (right - left) / 2 + left;
        build(node * 2 + 1, left, mid, nums);
        build(node * 2 + 2, mid + 1, right, nums);
        segmentTree[node] = max(segmentTree[node * 2 + 1], segmentTree[node * 2 + 2]);
    }

    int range(int node, int start, int end, int left, int right) {
        if (left == start && right == end) {
            return segmentTree[node];
        }
        int mid = (right - left) / 2 + left;
        if (end <= mid) {
            return range(node * 2 + 1, start, end, left, mid);
        } else if (start > mid) {
            return range(node * 2 + 2, start, end, mid + 1, right);
        } else {
            return max(range(node * 2 + 1, start, mid, left, mid), range(node * 2 + 2, mid + 1, end, mid + 1, right));
        }
    }

public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        n = nums.size();
        segmentTree = vector<int>(4 * n);
        build(0, 0, n - 1, nums);
        vector<int> res;
        for (int i = 0; i <= n - k; i++) {
            res.push_back(range(0, i, i + k - 1, 0, n - 1));
        }

        return res;
    }
};