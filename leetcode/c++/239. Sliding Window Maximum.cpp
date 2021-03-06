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
