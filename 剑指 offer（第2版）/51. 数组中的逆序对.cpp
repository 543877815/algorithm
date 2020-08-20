// base 遍历两边 时间复杂度：O(n^2)
// 归并排序
// 时间复杂度：O(nlogn)
// 空间复杂度：O(n)
class Solution {
private:
    int reversePairsCore(vector<int> &nums, vector<int> &copy, int start, int end) {
        if (start == end) {
            copy[start] = nums[start];
            return 0;
        }

        int length = (end - start) / 2;

        int left = reversePairsCore(copy, nums, start, start + length);
        int right = reversePairsCore(copy, nums, start + length + 1, end);

        // i 初始化为前半段最后一个数字的下标
        int i = start + length;
        // j 初始化为后半段最后一个数字的下标
        int j = end;
        int indexCopy = end;
        int count = 0;

        while (i >= start && j >= start + length + 1) {
            if (nums[i] > nums[j]) {
                copy[indexCopy--] = nums[i--];
                count += j - start - length;
            } else {
                copy[indexCopy--] = nums[j--];
            }
        }

        for (; i >= start; i--) copy[indexCopy--] = nums[i];
        for (; j >= start + length + 1; j--) copy[indexCopy--] = nums[j];

        return left + right + count;
    }

public:
    int reversePairs(vector<int> &nums) {
        int n = nums.size();
        if (n == 0) return 0;
        vector<int> copy(n);
        for (int i = 0; i < n; i++) copy[i] = nums[i];
        return reversePairsCore(nums, copy, 0, n - 1);
    }
};