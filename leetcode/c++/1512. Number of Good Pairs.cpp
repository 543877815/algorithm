// 遍历
// 时间复杂度：O(n^2)
// 空间复杂度：O(1)
class Solution {
public:
    int numIdenticalPairs(vector<int> &nums) {
        int res = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] == nums[j]) res++;
            }
        }
        return res;
    }
};

// 哈希表
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    int numIdenticalPairs(vector<int> &nums) {
        int res = 0;
        unordered_map<int, int> record;
        for (int num: nums) {
            record[num]++;
        }

        for (const auto &[k, v] :record) {
            res += v * (v - 1) / 2;
        }

        return res;
    }
};