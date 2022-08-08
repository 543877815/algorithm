// 超时
// 时间复杂度：O(n^2)
// 空间复杂度：O(1)
class Solution {
public:
    int reversePairs(vector<int> &nums) {
        int n = nums.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if ((long) nums[i] > (long) 2 * nums[j]) res++;
            }
        }

        return res;
    }
};


// 归并排序
// 时间复杂度：O(nlogn)
// 空间复杂度：O(n)
class Solution {
public:
    void sort(vector<int> &nums, int left, int right) {
        if (left == right) return;
        int mid = left + (right - left) / 2;
        sort(nums, left, mid);
        sort(nums, mid + 1, right);
        merge(nums, left, mid, right);
    }
    vector<int> tmp;
    int res = 0;

    void merge(vector<int> &nums, int left, int mid, int right) {
        for (int i = left; i <= right; i++) {
            tmp[i] = nums[i];
        }

        int i = left, j = mid + 1;
        while (i <= mid) {
            while (j <= right && (long) nums[i] > (long) nums[j] * 2) {
                j++;
            }
            res += j - (mid + 1);
            i++;
        }

        i = left;
        j = mid + 1;
        for (int k = left; k <= right; k++) {
            if (i == mid + 1) {
                nums[k] = tmp[j++];
            } else if (j == right + 1) {
                nums[k] = tmp[i++];
            } else if (tmp[i] > tmp[j]) {
                nums[k] = tmp[j++];
            } else {
                nums[k] = tmp[i++];
            }
        }
    }

    int reversePairs(vector<int> &nums) {
        int n = nums.size();
        tmp = vector<int>(n);
        sort(nums, 0, n - 1);
        return res;
    }
};