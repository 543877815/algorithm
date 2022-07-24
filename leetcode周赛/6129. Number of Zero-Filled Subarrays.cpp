// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    long long zeroFilledSubarray(vector<int> &nums) {
        int n = nums.size();
        long long res = 0;
        vector<int> counter;
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) count++;
            else {
                if (count != 0) {
                    counter.push_back(count);
                    count = 0;
                }
            }
        }

        if (count > 0) counter.push_back(count);

        for (int i = 0; i < counter.size(); i++) {
            long long total = (long long) counter[i];
            res += (1 + total) * total / 2;
        }

        return res;
    }
};