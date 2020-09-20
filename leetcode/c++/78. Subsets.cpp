

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **subsets(int *nums, int numsSize, int *returnSize, int **returnColumnSizes) {
    int size = (int) pow(2, numsSize);
    int **ans = (int **) malloc(sizeof(int *) * size);
    for (int i = 0; i < size; i++) {
        ans[i] = (int *) malloc(sizeof(int) * numsSize);
    }

    *returnSize = size;
    *returnColumnSizes = (int *) malloc(sizeof(int) * size);
    for (int i = 0; i < (1 << numsSize); i++) {
        int index = 0;
        for (int j = 0; j < numsSize; j++) {
            if (((i >> j) & 1) == 1) ans[i][index++] = nums[j];
        }
        (*returnColumnSizes)[i] = index;
    }

    return ans;
}


// c++
// 回溯，深度优先搜素
// 时间复杂度：O(n*2^n)
// 空间复杂度：O(n*2^n)
class Solution {
private:
    vector <vector<int>> res;

    void DFS(vector<int> &nums, vector<int> &t, int begin) {
        if (begin > nums.size()) return;
        res.push_back(t);
        for (int i = begin; i < nums.size(); i++) {
            t.push_back(nums[i]);
            DFS(nums, t, i + 1);
            t.pop_back();
        }
    }

public:
    vector <vector<int>> subsets(vector<int> &nums) {
        if (nums.empty()) return res;
        vector<int> t;
        DFS(nums, t, 0);
        return res;
    }
};