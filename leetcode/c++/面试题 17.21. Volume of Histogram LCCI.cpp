// 单调栈，双指针，动态规划
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    int trap(vector<int> &height) {
        stack<int> sk;
        int n = height.size();
        if (n == 0) return 0;
        vector<int> leftHighest(n, 0);
        vector<int> rightHighest(n, n - 1);
        for (int i = 0; i < n; i++) {
            if (sk.empty()) {
                sk.push(i);
            } else {
                leftHighest[i] = sk.top();
                if (height[sk.top()] < height[i]) sk.push(i);
            }
        }
        while (!sk.empty()) sk.pop();
        for (int i = n - 1; i >= 0; i--) {
            if (sk.empty()) {
                sk.push(i);
            } else {
                rightHighest[i] = sk.top();
                if (height[sk.top()] < height[i]) sk.push(i);
            }
        }
        while (!sk.empty()) sk.pop();
        /**
            index:        0 1 2 3 4 5 6 7  8  9  10 11
            height:       0 1 0 2 1 0 1 3  2  1  2  1
            leftHighest:  0 0 1 1 3 3 3 3  7  7  7  7
            rightHighest: 7 7 7 7 7 7 7 10 10 10 11 11
        */
        int res = 0;
        int right = rightHighest[0]; // 最高的长方形
        int left;
        while (right > 0) {
            left = leftHighest[right]; // 左边次高的长方形
            res += (right - left - 1) * min(height[left], height[right]);
            while (left != right - 1) {
                res -= height[--right];
            }
            right = left;
        }

        left = rightHighest[0]; // 最高的长方形
        while (left < n - 1) {
            right = rightHighest[left]; // 右边次高的长方形
            res += (right - left - 1) * min(height[left], height[right]);
            while (left + 1 != right) {
                res -= height[++left];
            }
            left = right;
        }
        return res;
    }
};

// 暴力解法：对于数组中的每个元素，我们找出下雨后水能达到的最高位置，等于两边最大高度的较小值减去当前高度的值。
class Solution {
public:
    int trap(vector<int> &height) {
        int ans = 0;
        int size = height.size();
        for (int i = 1; i < size - 1; i++) {
            int max_left = 0, max_right = 0;
            for (int j = i; j >= 0; j--) { //Search the left part for max bar size
                max_left = max(max_left, height[j]);
            }
            for (int j = i; j < size; j++) { //Search the right part for max bar size
                max_right = max(max_right, height[j]);
            }
            ans += min(max_left, max_right) - height[i];
        }
        return ans;
    }
};

// 动态规划
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    int trap(vector<int> &height) {
        int res = 0;
        int n = height.size();
        if (n == 0) return 0;
        vector<int> left_max(n), right_max(n);
        left_max[0] = height[0];
        for (int i = 1; i < n; i++) {
            left_max[i] = max(height[i], left_max[i - 1]);
        }
        right_max[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            right_max[i] = max(height[i], right_max[i + 1]);;
        }

        for (int i = 1; i < n - 1; i++) {
            res += min(left_max[i], right_max[i]) - height[i];
        }
        return res;
    }
};


// 单调栈
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    int trap(vector<int> &height) {
        int n = height.size();
        if (n == 0) return 0;
        int res = 0, current = 0;
        stack<int> sk;
        while (current < n) {
            // 出栈当且仅当当前高度大于栈的高度
            while (!sk.empty() && height[current] > height[sk.top()]) {
                int top = sk.top();
                sk.pop();
                if (sk.empty()) break;
                int distance = current - sk.top() - 1;
                int bounded_height = min(height[current], height[sk.top()]) - height[top];
                res += distance * bounded_height;
            }
            sk.push(current++);
        }
        return res;
    }
};


// 双指针
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    int trap(vector<int> &height) {
        int n = height.size();
        if (n == 0) return 0;
        int left = 0, right = n - 1, res = 0, left_max = 0, right_max = 0;
        while (left <= right) {
            if (left_max < right_max) {
                res += max(0, left_max - height[left]);
                left_max = max(left_max, height[left]);
                left++;
            } else {
                res += max(0, right_max - height[right]);
                right_max = max(right_max, height[right]);
                right--;
            }
        }
        return res;
    }
};