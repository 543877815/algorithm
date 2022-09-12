// 时间复杂度：O(nlogn)
// 空间复杂度：O(n)
class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int, int> record;
        int res = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 0) {
                record[nums[i]]++;
            }
        }

        if (record.size() == 0) return -1;
        int _max = 0;
        for (auto &[key, value]: record) {
            if (value > _max) {
                _max = value;
                res = key;
            }
        }

        return res;
    }
};