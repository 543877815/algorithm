int findMaxConsecutiveOnes(int *nums, int numsSize) {
    int maxNum = 0;
    int count = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 1) count++;
        else count = 0;
        if (count > maxNum) maxNum = count;
    }
    return maxNum;
}


// 双指针
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int> &nums) {
        int n = nums.size();
        int left = 0, right = 0;
        int maxn = 0;
        while (right < n) {
            if (nums[right] != 1) left = right + 1;
            right++;
            maxn = max(maxn, right - left);
        }
        return maxn;
    }
};