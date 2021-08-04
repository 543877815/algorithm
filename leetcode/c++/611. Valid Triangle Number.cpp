// 排序+二分查找
// 时间复杂度：O(n^2logn)
// 空间复杂度：O(logn)
class Solution {
public:
    int triangleNumber(vector<int> &nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int left = j + 1, right = n - 1, k = j;
                while (left <= right) {
                    int middle = left + (right - left) / 2;
                    if (nums[middle] < nums[i] + nums[j]) {
                        k = middle;
                        left = middle + 1;
                    } else {
                        right = middle - 1;
                    }
                }

                res += k - j;
            }
        }
        return res;
    }
};

// 排序+二分查找
// 时间复杂度：O(n^2)
// 空间复杂度：O(logn)
class Solution {
public:
    int triangleNumber(vector<int> &nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int i = 0; i < n; i++) {
            int k = i;
            for (int j = i + 1; j < n; j++) {
                while (k + 1 < n && nums[k + 1] < nums[i] + nums[j]) {
                    k++;
                }
                res += max(k - j, 0);
            }
        }
        return res;
    }
};