// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    vector<int> shuffle(vector<int> &nums, int n) {
        int i = 0, j = n;
        vector<int> res(2 * n);
        int idx = 0;
        while (i < n && j < 2 * n) {
            res[idx++] = nums[i++];
            res[idx++] = nums[j++];
        }
        return res;
    }
};