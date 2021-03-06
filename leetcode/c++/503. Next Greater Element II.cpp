// 单调栈
// 空间复杂度：O(n)
// 时间复杂度：O(n)
class Solution {
public:
    vector<int> nextGreaterElements(vector<int> &nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        if (n <= 1) return res;
        stack<int> s;
        for (int i = 0; i < n; i++) {
            while (!s.empty() && nums[s.top()] < nums[i]) {
                res[s.top()] = nums[i];
                s.pop();
            }
            s.push(i);
        }
        // s 降序
        int index = s.top() + 1;
        int tmp = s.top(); // 防止二次循环
        while (!s.empty() && s.top() != index) {
            if (tmp == index) break;
            if (index == n) index = 0;
            while (nums[s.top()] < nums[index]) {
                res[s.top()] = nums[index];
                s.pop();
            }
            index++;
        }
        return res;
    }
};