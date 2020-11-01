// 哈希表
// 时间复杂度：O(n)
// 空间复杂度：O(n）
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> hash;
        for(int i = 0; i < arr.size(); i++) {
            hash[arr[i]]++;
        }
        unordered_map<int, bool> count;
        for (auto &i : hash) {
            if (count.count(i.second) == 0) {
                count[i.second] = true;
            } else {
                return false;
            }
        }
        return true;
    }
};