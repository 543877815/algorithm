

int removeDuplicates(int *nums, int numsSize) {
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == nums[i - 1]) {
            for (int j = i; j < numsSize - 1; j++) {
                nums[j] = nums[j + 1];
            }
            i--;
            numsSize--;
        }
    }
    return numsSize;
}

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        if (nums.size() < 2)
            return nums.size();
        int k = 1;
        for (int i = 1; i < nums.size(); i++)
            if (nums[k - 1] < nums[i]) {
                nums[k++] = nums[i];
            }
        return k;
    }
};


int removeDuplicates(vector<int>& nums) {
    if (nums.size() < 2) return nums.size();
    int j = 0;
    for (int i = 1; i < nums.size(); i++)
        if (nums[j] != nums[i]) nums[++j] = nums[i];
    return ++j;
}