// 线状树
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class NumArray {
private:
    vector<int> segmenTree;
    int n;

    void build(int node, int left, int right, vector<int> &nums) {
        if (left == right) {
            segmenTree[node] = nums[left];
            return;
        }

        int mid = (right - left) / 2 + left;
        build(node * 2 + 1, left, mid, nums);
        build(node * 2 + 2, mid + 1, right, nums);
        segmenTree[node] = segmenTree[node * 2 + 1] + segmenTree[node * 2 + 2];
    }

    void change(int index, int val, int node, int left, int right) {
        if (left == right) {
            segmenTree[node] = val;
            return;
        }
        int mid = (right - left) / 2 + left;
        if (index <= mid) change(index, val, node * 2 + 1, left, mid);
        else change(index, val, node * 2 + 2, mid + 1, right);
        segmenTree[node] = segmenTree[node * 2 + 1] + segmenTree[node * 2 + 2];
    }

    int range(int node, int start, int end, int left, int right) {
        if (left == start && right == end) {
            return segmenTree[node];
        }
        int mid = (right - left) / 2 + left;
        if (end <= mid) {
            return range(node * 2 + 1, start, end, left, mid);
        } else if (start > mid) {
            return range(node * 2 + 2, start, end, mid + 1, right);
        } else {
            return range(node * 2 + 1, start, mid, left, mid) + range(node * 2 + 2, mid + 1, end, mid + 1, right);
        }
    }

public:
    NumArray(vector<int> &nums) : n(nums.size()), segmenTree(nums.size() * 4) {
        build(0, 0, n - 1, nums);
    }

    void update(int index, int val) {
        change(index, val, 0, 0, n - 1);
    }

    int sumRange(int start, int end) {
        return range(0, start, end, 0, n - 1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */