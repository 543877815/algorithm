// 枚举
// 时间复杂度：O(n^2)
// 空间复杂度：O(1)
class Solution {
public:
    int subarraySum(vector<int> &nums, int k) {
        int n = nums.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            int sum = nums[i];
            if (sum == k) res++;
            for (int j = i + 1; j < n; j++) {
                sum += nums[j];
                if (sum == k) res++;
            }
        }
        return res;
    }
};


// 哈希表 + 前缀和
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    int subarraySum(vector<int> &nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int count = 0, pre = 0;
        for (auto &x:nums) {
            pre += x;
            if (mp.find(pre - k) != mp.end()) {
                count += mp[pre - k];
            }
            mp[pre]++;
        }
        return count;
    }
};
