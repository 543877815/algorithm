// 时间复杂度：O(nlognlogm)
// 空间复杂度：O(logn)
class Solution {
public:
    string largestNumber(vector<int> &nums) {
        string res;
        int n = nums.size();
        if (n == 0) return res;

        sort(nums.begin(), nums.end(), [](const int &x, const int &y) {
            long sx = 10, sy = 10;
            while (sx <= x) {
                sx *= 10;
            }
            while (sy <= y) {
                sy *= 10;
            }
            return sy * x + y > sx * y + x;
        });

        if (nums[0] == 0) {
            return "0";
        }

        for (int i = 0; i < n; i++) {
            res += to_string(nums[i]);
        }

        return res;
    }
};