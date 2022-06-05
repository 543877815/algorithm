// 栈
// 时间复杂度：O(n^2)
// 空间复杂度：O(n)
class Solution {
public:
    int minMaxGame(vector<int> &nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        queue<int> q;
        for (int i = 0; i < n; i++) {
            q.push(nums[i]);
        }

        int m = q.size();
        while (q.size() != 1) {
            int a, b;
            for (int i = 0; i < m / 2; i++) {
                a = q.front();
                q.pop();
                b = q.front();
                q.pop();
                if (i % 2 == 0) q.push(min(a, b));
                else q.push(max(a, b));
            }
            m = q.size();
        }

        return q.front();
    }
};