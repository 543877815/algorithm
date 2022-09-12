// 线段树
// 时间复杂度：O(nlogn)
// 空间复杂度：O(nlogn)
class Solution {
public:
    vector<int> segmentTree;
    void update(int index, int val, int node, int left, int right) {
        if (left == right) {
            segmentTree[node] = val;
            return;
        }
        int mid = (right - left) / 2 + left;
        if (index <= mid) update(index, val, node * 2 + 1, left, mid);
        else update(index, val, node * 2 + 2, mid + 1, right);
        segmentTree[node] = max(segmentTree[node * 2 + 1], segmentTree[node * 2 + 2]);
    }

    int range(int node, int start, int end, int left, int right) {
        if (left == start && end == right) return segmentTree[node];
        int mid = (right - left) / 2 + left;
        if (end <= mid) {
            return range(node * 2 + 1, start, end, left, mid);
        } else if (start > mid) {
            return range(node * 2 + 2, start, end, mid + 1, right);
        } else {
            return max(range(node * 2 + 1, start, mid, left, mid), range(node * 2 + 2, mid + 1, end, mid + 1, right));
        }
    }

    int lengthOfLIS(vector<int>& nums, int k) {
        int n = nums.size();
        int u = *max_element(nums.begin(), nums.end()) + 1;
        segmentTree = vector<int>(4 * u, 0);
        int res = 0;
        for (int i = 0; i < n; i++) {
            int v = range(0, max(0, nums[i] - k), nums[i] - 1, 0, u - 1);
            res = max(res, v + 1);
            update(nums[i], v + 1, 0, 0, u - 1);
        }
        return res;
    }
};