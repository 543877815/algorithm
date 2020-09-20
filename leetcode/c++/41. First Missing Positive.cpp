// 使用辅助数组
// 空间复杂度：O(n)
// 时间复杂度：O(n)
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();
        vector<int>tmp (len, 0);
        for (int num : nums) {
            if (num <= len && num > 0) tmp[num-1] = num;
        }
        for (int i = 0; i < tmp.size(); i++) {
            if (!tmp[i]) {
                return i + 1;
            }
        }
        return len + 1;
    }
};

// 不使用辅助空间
// 时间复杂度：O(n)
// 空间复杂度：O(1)