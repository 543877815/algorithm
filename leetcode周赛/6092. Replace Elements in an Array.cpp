// 哈希表
// 时间复杂度：O(n+m)
// 空间复杂度：O(n)
class Solution {
public:
    vector<int> arrayChange(vector<int> &nums, vector <vector<int>> &operations) {
        unordered_map<int, int> mymap;
        int n = nums.size();
        int m = operations.size();

        for (int i = 0; i < n; i++) {
            mymap[nums[i]] = i;
        }

        for (int i = 0; i < m; i++) {
            int x = operations[i][0];
            int y = operations[i][1];

            nums[mymap[x]] = y;
            mymap[y] = mymap[x];
            mymap.erase(x);
        }

        return nums;
    }
};