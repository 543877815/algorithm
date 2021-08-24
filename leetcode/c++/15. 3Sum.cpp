// 250用例超时

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int cmp(const void *a, const void *b) {
    return *(int *) a - *(int *)b;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    qsort(nums, numsSize, sizeof(int), cmp);
    
    int number = (numsSize * (numsSize-1) * (numsSize-2)) / 6;
    int **ans = (int **) malloc (sizeof(int*) * number);
    for (int i = 0; i < number; i++) {
        ans[i] = (int *)malloc(sizeof(int) * 3);
    }
    int index = 0;
    for (int i = 0; i < numsSize - 2; i++) {
        if (nums[i] > 0) break;
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        int left = i + 1;
        int right = numsSize - 1;
        while(left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == 0) {
                ans[index][0] = nums[i];
                ans[index][1] = nums[left++];
                ans[index][2] = nums[right--];
                while(left < numsSize && nums[left]==nums[left-1]) left++;
                while(right > 0 && nums[right]==nums[right+1]) right--;
                index ++;
            } else if (sum > 0) {
                right --;
            } else {
                left ++;
            }
        }
    }
    
    *returnColumnSizes = (int *)malloc(sizeof(int)*index);
    for(int i = 0; i < index; i++){
        (*returnColumnSizes)[i] = 3;
    }
    
    *returnSize = index;
    return ans;
}


// 双指针
// 时间复杂度：O(n^2)
// 空间复杂度：O(1)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() < 3) return res;
        sort(nums.begin(), nums.end());

        int left, right, sum;
        for (int i = 0; i < nums.size() - 2; i++) {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i-1]) continue;
            left = i + 1;
            right = nums.size() - 1;
            while (left < right) {
                sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) {
                    vector<int> tmp = {nums[i], nums[left++], nums[right--]};
                    res.push_back(tmp);
                    while(left < right && nums[left]==nums[left-1]) left++;
                    while(left < right && nums[right]==nums[right+1]) right--;
                } else if (sum < 0) {
                    left++;
                } else {
                    right--;
                }

            }
        }
        return res;
    }
};