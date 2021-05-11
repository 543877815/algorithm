// set去重+二分搜索
// 时间复杂度：O(n+nlogn)
// 空间复杂度：O(n)
class Solution {
public:
    int minDays(vector<int> &bloomDay, int m, int k) {
        int n = bloomDay.size();
        if (n < m * k) return -1;
        set<int> st(bloomDay.begin(), bloomDay.end()); // set 去重
        vector<int> vt(st.begin(), st.end()); // 方便遍历
        int left = 0, right = vt.size() - 1;
        int res = INT_MAX;
        while (left <= right) {
            int middle = (right + left) / 2;
            int day = vt[middle];
            int count = 0, bunch = 0;
            for (int i = 0; i < n; i++) {
                if (day >= bloomDay[i]) {
                    count++;
                } else {
                    count = 0;
                }
                if (count >= k && count % k == 0) {
                    bunch++;
                    if (bunch == m) {
                        res = min(res, day);
                    }
                }
            }
            if (day == res) right = middle - 1;
            else left = middle + 1;
        }
        return res == INT_MAX ? -1 : res;
    }
};

// 二分搜索 + 排序
// 时间复杂度：O(n + nlogn)
// 空间复杂度：O(n)
class Solution {
public:
    int minDays(vector<int> &bloomDay, int m, int k) {
        int n = bloomDay.size();
        if (n < m * k) return -1;
        vector<int> vt(bloomDay.begin(), bloomDay.end()); // 方便遍历
        sort(vt.begin(), vt.end());
        int left = 0, right = vt.size() - 1;
        int res = INT_MAX;
        while (left <= right) {
            int middle = (right + left) / 2;
            int day = vt[middle];
            int count = 0, bunch = 0;
            for (int i = 0; i < n; i++) {
                if (day >= bloomDay[i]) {
                    count++;
                } else {
                    count = 0;
                }
                if (count >= k && count % k == 0) {
                    bunch++;
                    if (bunch == m) {
                        res = min(res, day);
                    }
                }
            }
            if (day == res) right = middle - 1;
            else left = middle + 1;
        }
        return res == INT_MAX ? -1 : res;
    }
};

// 二分搜索
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    int minDays(vector<int> &bloomDay, int m, int k) {
        int n = bloomDay.size();
        if (n < m * k) return -1;
        int left = INT_MAX, right = INT_MIN;
        for (int i = 0; i < n; i++) {
            left = min(left, bloomDay[i]);
            right = max(right, bloomDay[i]);
        }
        int res = INT_MAX;
        while (left <= right) {
            int middle = (right + left) / 2;
            int count = 0, bunch = 0;
            for (int i = 0; i < n; i++) {
                if (middle >= bloomDay[i]) count++;
                else count = 0;
                if (count >= k && count % k == 0) {
                    bunch++;
                    if (bunch == m) {
                        res = min(res, middle);
                    }
                }
            }
            if (middle == res) right = middle - 1;
            else left = middle + 1;
        }
        return res == INT_MAX ? -1 : res;
    }
};