// 异或
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            res ^= nums[i];
        }
        return res;
    }
};

// 二分查找
// 时间复杂度：O(n)
// 空间复杂度：O(1)