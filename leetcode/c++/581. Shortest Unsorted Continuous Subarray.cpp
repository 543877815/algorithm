// 快速排序
// 时间复杂度：O(nlogn)
// 空间复杂度：O(n)
class Solution {
public:
    int findUnsortedSubarray(vector<int> &nums) {
        int n = nums.size();
        vector<int> tmp = vector<int>(n);

        for (int i = 0; i < n; i++) {
            tmp[i] = nums[i];
        }

        sort(tmp.begin(), tmp.end());

        int num = 0;
        int left = 0;

        while (left < n && nums[left] == tmp[left]) {
            num++;
            left++;
        }

        int right = n - 1;
        while (right >= left && nums[right] == tmp[right]) {
            num++;
            right--;
        }

        return n - num;
    }
};


// 一次遍历
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxn = INT_MIN;
        int minn = INT_MAX;
        int left = -1, right = -1;
        // 若当前元素不是最大，则边界右移
        // 若当前元素不是最小，则边界左移
        for (int i = 0; i < n; i++) {
            if (maxn <= nums[i]) {
                maxn = nums[i];
            } else {
                right = i;   // 最大元素决定右边界
            }

            if (minn >= nums[n - i - 1]) {
                minn = nums[n - i - 1];
            } else {
                left = n - i - 1;   // 最小元素决定左边界
            }
        }

        return right == -1 ? 0 : right - left + 1;
    }
};