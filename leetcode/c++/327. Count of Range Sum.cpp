// 动态规划，超时
// 时间复杂度：O(n^2)
// 空间复杂度：O(n^2)
class Solution {
public:
    int countRangeSum(vector<int> &nums, int lower, int upper) {
        int n = nums.size();
        int res = 0;
        vector <vector<long>> dp(n + 1, vector<long>(n + 1, 0));
        for (int i = 1; i < n + 1; i++) dp[i][i] = nums[i - 1];
        for (int i = 1; i < n + 1; i++) {
            for (int j = i + 1; j < n + 1; j++) {
                dp[i][j] = dp[i][j - 1] + nums[j - 1];
            }
        }
        for (int i = 1; i < n + 1; i++) {
            for (int j = i; j < n + 1; j++) {
                if (dp[i][j] <= upper && dp[i][j] >= lower) res++;
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
    int res = 0;
    vector<long> tmp;
    int upper;
    int lower;

    void merge(vector<long> &arr, int left, int mid, int right) {
        for (int i = left; i <= right; i++) {
            tmp[i] = arr[i];
        }

        int start = mid + 1, end = mid + 1;
        for (int i = left; i <= mid; i++) {
            while (start <= right && arr[start] - arr[i] < this->lower) {
                start++;
            }
            while (end <= right && arr[end] - arr[i] <= this->upper) {
                end++;
            }
            res += end - start;
        }

        int i = left, j = mid + 1;
        for (int k = left; k <= right; k++) {
            if (i == mid + 1) {
                arr[k] = tmp[j++];
            } else if (j == right + 1) {
                arr[k] = tmp[i++];
            } else if (tmp[i] > tmp[j]) {
                arr[k] = tmp[j++];
            } else {
                arr[k] = tmp[i++];
            }
        }
    }

    void sort(vector<long> &arr, int left, int right) {
        if (left == right) return;
        int mid = left + (right - left) / 2;
        sort(arr, left, mid);
        sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }

    int countRangeSum(vector<int> &nums, int lower, int upper) {
        int n = nums.size();
        vector<long> presum(n + 1, 0);
        this->lower = lower;
        this->upper = upper;
        for (int i = 0; i < n; i++) {
            presum[i + 1] = presum[i] + (long) nums[i];
        }

        tmp = vector<long>(n + 1);
        sort(presum, 0, n);

        return res;
    }
};