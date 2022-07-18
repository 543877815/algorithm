// 哈希表
// 时间复杂度：O(n+m)
// 空间复杂度：O(n+m)
class Solution {
public:
    int minOperations(vector<int> &nums, vector<int> &numsDivide) {
        int n = nums.size();
        int m = numsDivide.size();
        if (n == 0 || m == 0) return -1;

        map<int, int> map1;
        unordered_map<int, int> map2;

        int min_num = INT_MAX;
        int max_num = INT_MIN;
        for (int i = 0; i < n; i++) {  // nlogn
            map1[nums[i]]++;
            max_num = min(max_num, nums[i]);
            min_num = min(min_num, nums[i]);
        }

        if (min_num == 1) return 0;
        for (int i = 0; i < m; i++) {
            map2[numsDivide[i]]++;
        }

        int res = 0;
        for (auto &[key1, value1]: map1) {
            int valid = true;
            for (auto &[key2, value2]: map2) {
                if (key2 % key1 != 0) {
                    valid = false;
                    break;
                }
            }
            if (!valid) {
                res += value1;
            } else return res;
        }

        return -1;
    }
};