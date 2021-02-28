// 直接遍历
// 时间复杂度：O(n)
// 时间复杂度：O(n)
class NumArray {
public:
    vector<int> numbers;

    NumArray(vector<int> &nums) {
        numbers = nums;
    }

    int sumRange(int i, int j) {
        int sum = 0;
        for (int k = i; k <= j; k++) {
            sum += numbers[k];
        }

        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */


// 前缀和
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class NumArray {
public:
    vector<int> sums;

    NumArray(vector<int> &nums) {
        int n = nums.size();
        sums = vector<int>(n);
        for (int i = 0; i < n; i++) {
            if (i == 0) sums[i] = nums[i];
            else sums[i] = sums[i - 1] + nums[i];
        }
    }

    int sumRange(int i, int j) {
        if (i == 0) return sums[j];
        else return sums[j] - sums[i - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */