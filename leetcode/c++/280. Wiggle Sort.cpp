void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void wiggleSort(int *nums, int numsSize) {
    for (int i = 0; i < numsSize - 1; i++) {
        if ((i % 2 == 0) == (nums[i] > nums[i + 1])) {
            swap(&nums[i], &nums[i + 1]);
        }
    }
}


// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    void wiggleSort(vector<int> &nums) {
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            if ((i % 2 == 0) == (nums[i] > nums[i + 1])) {
                swap(nums[i], nums[i + 1]);
            }
        }
    }
};