// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int tmp = 0;
        for (int i = 0; i < nums.size(); i++) {
            tmp ^= nums[i];
        }

        int div = 1;
        while ((tmp & div) == 0) {
            div <<= 1;
        }

        int r1 = 0, r2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] & div) {
                r1 ^= nums[i];
            } else {
                r2 ^= nums[i];
            }
        }

        return {r1, r2};
    }
};