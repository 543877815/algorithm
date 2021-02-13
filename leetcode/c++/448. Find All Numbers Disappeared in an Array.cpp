// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int> &nums) {
        int n = nums.size();
        vector<int> res;
        int tmp;
        for (int i = 0; i < n; i++) {
            while (nums[i] != i + 1) {
                if (nums[i] == nums[nums[i] - 1]) break;
                tmp = nums[nums[i] - 1];
                nums[nums[i] - 1] = nums[i];
                nums[i] = tmp;
            }
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1)
                res.push_back(i + 1);
        }
        return res;
    }
};

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int> &nums) {
        int n = nums.size();
        for (auto &num : nums) {
            int x = (num - 1) % n;
            nums[x] += n;
        }
        vector<int> ret;
        for (int i = 0; i < n; i++) {
            if (nums[i] <= n) {
                ret.push_back(i + 1);
            }
        }
        return ret;
    }
};

