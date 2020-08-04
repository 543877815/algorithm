

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int factorial(int n) {
    if (n == 1) return 1;
    return n * factorial(n - 1);
}

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void backtrack(int **res, int *nums, int *tmp, int index, int *loc, int max) {
    if (index == max) {
        int *save = (int *) malloc(sizeof(int) * (max + 1));
        tmp[index] = 0;
        memcpy(save, tmp, sizeof(int) * max);
        res[(*loc)++] = save;
        return;
    }

    for (int i = index; i < max; i++) {
        tmp[index] = nums[i];
        swap(&nums[index], &nums[i]);
        backtrack(res, nums, tmp, index + 1, loc, max);
        swap(&nums[index], &nums[i]);
    }
}

int **permute(int *nums, int numsSize, int *returnSize, int **returnColumnSizes) {
    // malloc
    int size = factorial(numsSize);
    int **res = (int **) malloc(sizeof(int *) * size);
    for (int i = 0; i < size; i++) {
        res[i] = (int *) malloc(sizeof(int) * (numsSize + 1));
    }

    // backtrack
    int *tmp = (int *) malloc(sizeof(int) * (numsSize + 1));
    int loc = 0;
    backtrack(res, nums, tmp, 0, &loc, numsSize);

    // return
    *returnSize = loc;
    *returnColumnSizes = (int *) malloc(sizeof(int) * loc);
    for (int i = 0; i < size; i++) {
        (*returnColumnSizes)[i] = numsSize;
    }
    return res;
}


// c++ 回溯
// 时间复杂度：O(n!)
// 空间复杂度：O(n)
class Solution {
private:
    vector <vector<int>> res;
    vector<bool> used;

    // p中保存了一个有index个元素的排列
    // 向这个排列的末尾添加第index+1个元素，获得一个有index+1个元素的排列
    void generatePermutation(const vector<int> &nums, int index, vector<int> &p) {
        if (index == nums.size()) {
            res.push_back(p);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (!used[i]) {
                p.push_back(nums[i]);
                used[i] = true;
                generatePermutation(nums, index + 1, p);
                used[i] = false;
                p.pop_back();
            }
        }

    }

public:
    vector <vector<int>> permute(vector<int> &nums) {
        res.clear();
        if (nums.size() == 0) return res;

        used = vector<bool>(nums.size(), false);
        vector<int> p;
        generatePermutation(nums, 0, p);

        return res;
    }
};