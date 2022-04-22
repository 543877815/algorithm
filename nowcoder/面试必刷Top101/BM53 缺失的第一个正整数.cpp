// 哈希表
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param nums int整型vector
     * @return int整型
     */
    int minNumberDisappeared(vector<int> &nums) {
        // write code here
        unordered_map<int, int> hashmap;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            hashmap[nums[i]]++;
        }

        for (int i = 1; i <= n + 1; i++) {
            if (hashmap.find(i) == hashmap.end()) return i;
        }

        return -1;
    }
};

// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param nums int整型vector
     * @return int整型
     */
    int minNumberDisappeared(vector<int> &nums) {
        // write code here
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            while (nums[i] > 0 && nums[i] < n && nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]); // 防止越界，并把数组放在他应该在的位置
            }
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) return i + 1;
        }

        return n + 1;
    }
};