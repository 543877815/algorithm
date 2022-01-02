// 单调栈
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    int largestRectangleArea(vector<int> &heights) {
        int n = heights.size();
        // left 表示左边比自己小的索引, right 表示右边比自己小的索引
        vector<int> left = vector<int>(n, -1);
        vector<int> right = vector<int>(n, n);
        stack<int> stk;
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && heights[stk.top()] >= heights[i]) {
                stk.pop();
            }
            left[i] = stk.empty() ? -1 : stk.top();
            stk.push(i);
        }

        while (!stk.empty()) stk.pop();
        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && heights[stk.top()] >= heights[i]) {
                stk.pop();
            }
            right[i] = stk.empty() ? n : stk.top();
            stk.push(i);
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            res = max(res, (right[i] - left[i] - 1) * heights[i]);
        }

        return res;

    }
};

// 常数级别优化
class Solution {
public:
    int largestRectangleArea(vector<int> &heights) {
        int n = heights.size();
        // left 表示左边比自己小的索引, right 表示右边比自己小的索引
        vector<int> left = vector<int>(n, -1);
        vector<int> right = vector<int>(n, n);
        stack<int> stk;
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && heights[stk.top()] >= heights[i]) {
                right[stk.top()] = i;
                stk.pop();
            }
            left[i] = stk.empty() ? -1 : stk.top();
            stk.push(i);
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            res = max(res, (right[i] - left[i] - 1) * heights[i]);
        }

        return res;

    }
};