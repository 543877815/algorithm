// 哈希表
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    int findPairs(vector<int> &nums, int k) {
        int n = nums.size();
        unordered_map<int, int> record;
        for (int i = 0; i < n; i++) {
            record[nums[i]]++;
        }

        int res = 0;
        unordered_map<int, bool> visited;
        for (int i = 0; i < n; i++) {
            if (record.find(nums[i] - k) != record.end()) {
                if (k == 0) {
                    if (record[nums[i]] > 1 && !visited[nums[i]]) {
                        res++;
                        visited[nums[i]] = true;
                    }
                } else if (!visited[nums[i]]) {
                    visited[nums[i]] = true;
                    res++;
                }

            }
        }

        return res;
    }
};