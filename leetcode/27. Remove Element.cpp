

int removeElement(int *nums, int numsSize, int val) {
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == val) {
            for (int j = i; j < numsSize - 1; j++) {
                nums[j] = nums[j + 1];
            }
            i--;
            numsSize--;
        }
    }
    return numsSize;
}

// reference 283
class Solution {
public:
    int removeElement(vector<int> &nums, int val) {
        int k = 0;
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] != val)
                if (i != k)
                    swap(nums[k++], nums[i]);
                else
                    k++;
        return k;
    }
};