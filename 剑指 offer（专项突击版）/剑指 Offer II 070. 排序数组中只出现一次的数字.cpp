// 异或
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    int singleNonDuplicate(vector<int> &nums) {
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            res ^= nums[i];
        }
        return res;
    }
};

// 二分查找
// 时间复杂度：O(logn)
// 空间复杂度：O(1)
class Solution {
public:
    int singleNonDuplicate(vector<int> &nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        int left = 0, right = n - 1;
        while (left < right) {
            int middle = left + (right - left) / 2;
            if (nums[middle] != nums[middle + 1] && nums[middle] != nums[middle - 1]) {
                return nums[middle];
            } else {
                int diff = right - middle;
                if (diff % 2 == 0) {
                    if (nums[middle] == nums[middle - 1]) {
                        right = middle - 2;
                    } else if (nums[middle] == nums[middle + 1]) {
                        left = middle + 2;
                    }
                } else {
                    if (nums[middle] == nums[middle - 1]) {
                        left = middle + 1;
                    } else if (nums[middle] == nums[middle + 1]) {
                        right = middle - 1;
                    }
                }
            }
        }

        return nums[left];
    }
};

// 二分查找，仅对偶数进行索引
class Solution {
public:
    int singleNonDuplicate(vector<int> &nums) {
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (mid % 2 == 1) mid--;
            if (nums[mid] == nums[mid + 1]) {
                left = mid + 2;
            } else {
                right = mid;
            }
        }
        return nums[left];
    }
};