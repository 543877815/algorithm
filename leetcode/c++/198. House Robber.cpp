// 空间复杂度：O(n)
// 时间复杂度：O(n)
// F[x]：考虑偷取[x...n-1]范围里的房子
int max(int a, int b) {
    return a > b ? a : b;
}

int rob(int *nums, int numsSize) {
    if (numsSize == 0) return 0;
    if (numsSize == 1) return nums[0];
    int *F = (int *) malloc(sizeof(int) * numsSize);
    F[0] = nums[0];
    F[1] = max(nums[0], nums[1]);
    for (int i = 2; i < numsSize; i++) {
        F[i] = max(F[i - 1], F[i - 2] + nums[i]);
    }
    return F[numsSize - 1];
}

// 空间优化
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    int rob(vector<int> &nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        int first = nums[0], second = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++) {
            int tmp = second;
            second = max(first + nums[i], second);
            first = tmp;
        }
        return second;
    }
};

// 空间复杂度：O(n)
// 时间复杂度：O(n)
class Solution {
public:
    int rob(vector<int> &nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        vector<int> dp(n);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[n - 1];
    }
};
