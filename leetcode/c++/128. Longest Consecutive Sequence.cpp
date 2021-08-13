// 快速排序
// 时间复杂度：O(nlogn)
// 空间复杂度：O(logn)
class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (n == 0) return 0;
        int res = 1;
        int curr = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1] + 1) curr++;
            else if (nums[i] - nums[i - 1] > 1) curr = 1;
            res = max(res, curr);
        }

        return res;
    }
};

// 哈希表
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        int n = nums.size();
        unordered_map<int, int> record;
        for (int i = 0; i < n; i++) {
            record[nums[i]] = 1;
        }

        int res = 0;
        for (auto &[key, value] : record) {
            int num = key;
            if (record.find(num - 1) != record.end()) continue;
            while (record.find(num) != record.end()) {
                num++;
            }
            res = max(res, num - key);
        }
        return res;
    }
};