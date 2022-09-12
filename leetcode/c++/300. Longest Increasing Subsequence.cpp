// 动态规划
// 时间复杂度：O(n^2)
// 空间复杂度：O(n)
class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        int n = nums.size();
        if (n == 0) return 0;

        int max_num = 1;

        // dp[i] 表示以第i个数字为结尾的最长上升子序列的长度
        vector<int> dp(n, 1);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    max_num = max(max_num, dp[i]);
                }
            }
        }
        return max_num;
    }
};

// 贪心+二分搜索
// 空间复杂度：O(n)
// 时间复杂度：O(nlogn)
class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        int len = 1, n = (int) nums.size();
        if (n == 0) {
            return 0;
        }
        vector<int> d(n + 1, 0);
        d[len] = nums[0];
        for (int i = 1; i < n; ++i) {
            if (nums[i] > d[len]) {
                d[++len] = nums[i];
            } else {
                int pos = 0;
                auto it = lower_bound(d.begin() + 1, d.begin() + len + 1, nums[i]);
                if (it != d.end()) {
                    pos = (it - d.begin());
                }
                d[pos] = nums[i];
            }
        }
        return len;
    }
};

// 线段树
// 时间复杂度：O(nlogn)
// 空间复杂度：O(nlogn)
class Solution {
public:
    const int _MAX = 2500;
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

    int lengthOfLIS(vector<int> &nums) {
        int n = nums.size();
        segmentTree = vector<int>(4 * _MAX, 0);
        // 离散化
        set<int> s(nums.begin(), nums.end());
        int cnt = 1;
        unordered_map<int, int> m;
        for (int i: s) {
            m[i] = cnt++;
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            int v = range(0, 0, m[nums[i]] - 1, 0, _MAX - 1);
            res = max(res, v + 1);
            update(m[nums[i]], v + 1, 0, 0, _MAX - 1);
        }

        return res;
    }
};


// 线段树+离散化
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

    int lengthOfLIS(vector<int> &nums) {
        int n = nums.size();
        segmentTree = vector<int>(4 * n, 0);
        // 离散化
        set<int> s(nums.begin(), nums.end());
        int cnt = 1;
        unordered_map<int, int> m;
        for (int i: s) {
            m[i] = cnt++;
        }
        s.clear();
        int res = 0;
        for (int i = 0; i < n; i++) {
            int v = range(0, 0, m[nums[i]] - 1, 0, n - 1);
            res = max(res, v + 1);
            update(m[nums[i]], v + 1, 0, 0, n - 1);
        }

        return res;
    }
};