class Solution {
public:
    // 时间复杂度：O(n)
    // 空间复杂度：O(1)
    void sortColors(vector<int> &nums) {
        int count[3] = {0};
        for (int i = 0; i < nums.size(); i++) {
            count[nums[i]]++;
        }
        int index = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < count[i]; j++) {
                nums[index++] = i;
            }
        }

    }
};


class Solution {
public:
    // 时间复杂度： O(n)
    // 空间复杂度： O(1)
    void sortColors(vector<int> &nums) {
        int zero = -1;  // nums[0...zero]==0
        int two = nums.size();  // nums[two...n-1]==1
        for (int i = 0; i < two;) {
            if (nums[i] == 1)
                i++;
            else if (nums[i] == 2) {
                swap(nums[i], nums[--two]);
            } else {  // nums[i] == 0
                assert(nums[i] == 0);
                swap(nums[++zero], nums[i++]);
            }
        }
    }
};