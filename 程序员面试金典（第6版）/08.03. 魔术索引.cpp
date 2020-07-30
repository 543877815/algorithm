// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    int findMagicIndex(vector<int>& nums) {
        int res = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == i) {
                res = i;
                break;
            }
        }
        return res;
    }
};