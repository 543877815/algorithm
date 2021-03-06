// 线性解法
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> nums;
        while (n != 0) {
            nums.push_back(n % 10);
            n /= 10;
        }

        int size = nums.size();
        int index = -1;
        for (int i = 1; i < size; i++) {
            if (nums[i] < nums[i - 1]) {
                index = i;
                break;
            }
        }

        if (index == -1) return -1;

        for (int i = 0; i < size; i++) {
            if (nums[i] > nums[index]) {
                swap(nums[i], nums[index]);
                reverse(nums.begin(), nums.begin() + index);
                break;
            }
        }

        long long res = 0;

        for (int i = size - 1; i >= 0; i--) {
            res = res * 10 + nums[i];
            if (res > INT_MAX) return -1;
        }

        return (int) res;
    }
};