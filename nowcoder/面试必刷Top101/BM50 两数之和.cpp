// 哈希表
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    /**
     *
     * @param numbers int整型vector
     * @param target int整型
     * @return int整型vector
     */
    vector<int> twoSum(vector<int>& numbers, int target) {
        // write code here
        unordered_map<int, int> hashmap;
        vector<int> res = {-1, -1};
        int n = numbers.size();
        for (int i = 0; i < n; i++) {
            if (hashmap.find(target - numbers[i]) != hashmap.end()) {
                res[0] = hashmap[target - numbers[i]] + 1;
                res[1] = i + 1;
                return res;
            }
            hashmap[numbers[i]] = i;
        }
        return res;
    }
};