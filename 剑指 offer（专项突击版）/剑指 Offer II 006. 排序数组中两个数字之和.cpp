// 哈希表
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> res = vector<int>(2);
        int n = numbers.size();
        unordered_map<int, int> record;
        for (int i = 0; i < n; i++) {
            if (record.find(target - numbers[i]) == record.end()) {
                record[numbers[i]] = i;
            } else {
                res[0] = record[target - numbers[i]];
                res[1] = i;
                break;
            }
        }

        return res;
    }
};