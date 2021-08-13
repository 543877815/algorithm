// 等差数列+计算
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    int numberOfArithmeticSlices(vector<int> &nums) {
        int n = nums.size();
        if (n < 3) return 0;
        unordered_map<int, int> hashmap;
        for (int i = n - 1; i > 0; i--) {
            nums[i] = nums[i] - nums[i - 1];
        }
        int res = 0;
        int num = nums[1], val = 1;
        for (int i = 2; i < n; i++) {
            if (nums[i] == num) {
                res += val;
                val++;
            } else {
                num = nums[i];
                val = 1;
            }
        }
        return res;
    }
};


// 动态规划
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    int numberOfArithmeticSlices(vector<int> &nums) {
        int n = nums.size(), l = 0, ans = 0;
        for (int i = 2; i < n; i++)
            nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2] ? ans += ++l : l = 0;
        return ans;
    }
};