// 哈希表
// 时间复杂度：O(nlogn)
// 空间复杂度：O(n)

class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        int n = nums.size();
        unordered_map<int, int> mymap;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < nums[i].size(); j++) {
                mymap[nums[i][j]]++;
            }
        }

        vector<int> res;

        for (auto&[key, value]: mymap) {
            if (value == n) {
                res.push_back(key);
            }
        }

        sort(res.begin(), res.end());
        return res;
    }
};