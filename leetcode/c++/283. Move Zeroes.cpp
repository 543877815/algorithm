class Solution {
public:
    // 时间复杂度: O(n)
    // 空间复杂度：O(n)
    void moveZeroes(vector<int> &nums) {
        vector<int> nonZeroElements;

        for (int i = 0; i < nums.size(); i++)
            if (nums[i])
                nonZeroElements.push_back(nums[i]);

        for (int i = 0; i < nonZeroElements.size(); i++)
            nums[i] = nonZeroElements[i];

        for (int i = nonZeroElements.size(); i < nums.size(); i++)
            nums[i] = 0;
    }
};

class Solution {
public:
    // 时间复杂度: O(n)
    // 空间复杂度：O(1)
    void moveZeroes(vector<int> &nums) {
        int k = 0; // num中，[0...k)的元素均为非0元素
        for (int i = 0; i < nums.size(); i++)
            if (nums[i])
                nums[k++] = nums[i];
        for (int i = k; i < nums.size(); i++)
            nums[i] = 0;
    }
};


class Solution {
public:
    // 时间复杂度: O(n)
    // 空间复杂度：O(1)
    void moveZeroes(vector<int> &nums) {
        int k = 0; // num中，[0...k)的元素均为非0元素
        for (int i = 0; i < nums.size(); i++)
            if (nums[i]) {
                int tmp = nums[k];
                nums[k++] = nums[i];
                nums[i] = tmp;
            }
    }
};


class Solution {
public:
    // 时间复杂度: O(n)
    // 空间复杂度：O(1)
    void moveZeroes(vector<int> &nums) {
        int k = 0; // num中，[0...k)的元素均为非0元素
        for (int i = 0; i < nums.size(); i++)
            if (nums[i])
                if (i != k)
                    swap(nums[k++], nums[i]);
                else
                    k++;
    }
};