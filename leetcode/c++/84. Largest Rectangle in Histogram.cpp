// 单调栈
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    int largestRectangleArea(vector<int> &heights) {
        int n = heights.size();
        vector<int> right(n), left(n);

        stack<int> stk;
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && heights[stk.top()] >= heights[i]) stk.pop();
            left[i] = stk.empty() ? -1 : stk.top();
            stk.push(i);
        }

        stk = stack<int>();
        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && heights[stk.top()] >= heights[i]) stk.pop();
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


// 单调栈+常数优化(入栈决定左边界，出栈决定右边界)
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    int largestRectangleArea(vector<int> &heights) {
        int n = heights.size();
        vector<int> right(n, n), left(n);

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