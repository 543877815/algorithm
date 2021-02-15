// 贪心算法
// 时间复杂度：O(nlogn)
// 空间复杂度：O(logn)
class Solution {
public:
    int arrayPairSum(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int sum = 0;
        for (int i = 0; i < nums.size(); i += 2) {
            sum += nums[i];
        }
        return sum;
    }
};