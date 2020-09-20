// 暴力，超时
// 时间复杂度：O(n^2)
// 空间复杂度：O(1)
bool containsNearbyDuplicate(int *nums, int numsSize, int k) {
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] == nums[j] && j - i <= k) return true;
        }
    }
    return false;
}

// 使用查找表和滑动窗口
// 时间复杂度：O(n)
// 空间复杂度：O(k)
class Solution {
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k) {
        unordered_set<int> record;
        for (int i = 0; i < nums.size(); i++) {
            if (record.find(nums[i]) != record.end()) return true;
            record.insert(nums[i]);
            if (record.size() == k + 1) record.erase(nums[i - k])
        }
        return false;
    }
};

