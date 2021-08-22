// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    int pivotIndex(vector<int> &nums) {
        int presum = 0;
        for (int x :nums) {
            presum += x;
        }
        int leftSum = 0;
        for (int i = 0; i <= nums.size(); i++) {
            if (leftSum == presum - nums[i] - leftSum) {
                return i;
            }
            leftSum += nums[i];
        }
        return -1;
    }
};