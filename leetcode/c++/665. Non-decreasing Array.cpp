// 一次遍历
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    bool checkPossibility(vector<int> &nums) {
        int n = nums.size();
        int count = 0;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                count++;
                if (count >= 2) return false;
                if (i > 0 && nums[i + 1] < nums[i - 1]) {
                    nums[i + 1] = nums[i];
                }
            }

        }
        return true;
    }
};

class Solution {
public:
    bool checkPossibility(vector<int> &nums) {
        int n = nums.size();
        int count = 0;
        for (int i = 0; i < n - 1; i++) {
            int x = nums[i], y = nums[i + 1];
            if (x > y) {
                nums[i] = y;
                if (is_sorted(nums.begin(), nums.end())) return true;
                nums[i] = x; // 复原

                nums[i + 1] = x;
                return is_sorted(nums.begin(), nums.end());
            }

        }
        return true;
    }
};