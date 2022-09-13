// 时间复杂度：O(1)
// 空间复杂度：O(1)
class Solution {
public:
    int maximumSwap(int num) {
        vector<int> nums;
        while (num) {
            nums.push_back(num % 10);
            num /= 10;
        }
        int n = nums.size();
        vector <pair<int, int>> leftmost(n);
        int __max = 0;
        int __index = -1;
        for (int i = 0; i < n; i++) {
            leftmost[i] = {__max, __index};
            if (__max < nums[i]) {
                __index = i;
                __max = nums[i];
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            if (leftmost[i].first > nums[i]) {
                swap(nums[leftmost[i].second], nums[i]);
                break;
            }
        }

        int res = 0;
        for (int i = n - 1; i >= 0; i--) {
            res = res * 10 + nums[i];
        }

        return res;
    }
};