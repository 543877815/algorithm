// 使用56的函数
// 时间复杂度：O(nlogn)
// 空间复杂度：O(n);
class Solution {
public:
    vector <vector<int>> insert(vector <vector<int>> &intervals, vector<int> &newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        return merge(intervals);
    }

    vector <vector<int>> merge(vector <vector<int>> &intervals) {
        if (intervals.size() == 0) {
            return {};
        }
        sort(intervals.begin(), intervals.end());
        vector <vector<int>> merged;
        for (int i = 0; i < intervals.size(); ++i) {
            int L = intervals[i][0], R = intervals[i][1];
            if (!merged.size() || merged.back()[1] < L) {
                merged.push_back({L, R});
            } else {
                merged.back()[1] = max(merged.back()[1], R);
            }
        }
        return merged;
    }
};


// 先有序插入，再合并
// 时间复杂度：O(n)
// 空间复杂度：O(1)，除了存储返回的数组，空间复杂度为常数级
class Solution {
public:
    vector <vector<int>> insert(vector <vector<int>> &intervals, vector<int> &newInterval) {
        int n = intervals.size();
        // 插入有序数组
        for (int i = 0; i < n; i++) {
            if (i < n - 1) {
                if (newInterval[0] >= intervals[i][0] && newInterval[0] <= intervals[i + 1][0]) {
                    intervals.insert(intervals.begin() + i + 1, newInterval);
                }
            }
        }
        if (intervals.size() == n) {
            if (intervals.size() == 0) intervals.push_back(newInterval);
            else if (newInterval[0] >= intervals.back()[0]) intervals.push_back(newInterval);
            else (intervals.insert(intervals.begin(), newInterval));
        }

        // 合并
        vector <vector<int>> res;
        n = intervals.size();
        for (int i = 0; i < n; i++) {
            if (i != n - 1 && intervals[i][1] >= intervals[i + 1][0]) {
                intervals[i + 1][0] = intervals[i][0];
                if (intervals[i][1] >= intervals[i + 1][1]) {
                    intervals[i + 1][1] = intervals[i][1];
                }
            } else {
                res.push_back({intervals[i][0], intervals[i][1]});
            }
        }
        return res;
    }
};

// 直接插入合并
// 时间复杂度：O(n)
// 空间复杂度：O(1)，除了存储返回的数组，空间复杂度为常数级
class Solution {
public:
    vector <vector<int>> insert(vector <vector<int>> &intervals, vector<int> &newInterval) {
        int left = newInterval[0];
        int right = newInterval[1];
        bool places = false;
        vector <vector<int>> res;
        for (const auto &interval: intervals) {
            // 在右侧且无交集
            if (interval[0] > right) {
                if (!places) {
                    res.push_back({left, right});
                    places = true;
                }
                res.push_back(interval);

                // 在左侧且无交集
            } else if (interval[1] < left) {
                res.push_back(interval);

                // 有交集
            } else {
                left = min(left, interval[0]);
                right = max(right, interval[1]);
            }
        }

        if (!places) res.push_back({left, right});

        return res;
    }
};