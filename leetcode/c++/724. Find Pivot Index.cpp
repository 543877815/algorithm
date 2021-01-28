// 遍历
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    int pivotIndex(vector<int> &nums) {
        int n = nums.size();
        if (n == 0) return -1;
        int leftSum = 0, rightSum = 0;
        for (int i = 1; i < n; i++) {
            rightSum += nums[i];
        }
        int res = -1;
        int index = 0;
        while (leftSum != rightSum && index < n - 1) {
            leftSum += nums[index];
            rightSum -= nums[index + 1];
            index++;
        }

        return leftSum == rightSum ? index : res;
    }
};