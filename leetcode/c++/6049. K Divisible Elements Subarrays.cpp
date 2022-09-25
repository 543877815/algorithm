// 哈希表和深度优先搜索
// 时间复杂度：O(n^2)
// 空间复杂度：O(n)
class Solution {
public:
    unordered_map<int, bool> idx;
    map<vector<int>, bool> visited;
    int k;
    int res;

    void dfs(vector<int> &nums, vector<int> &tmp, int count, int index) {
        int n = nums.size();
        if (index == n || count > k) return;


        tmp.push_back(nums[index]);
        if (idx[index])count++;
        if (count <= k && visited.find(tmp) == visited.end()) {
            visited[tmp] = true;
            res++;
        }
        dfs(nums, tmp, count, index + 1);
        tmp.pop_back();


    }

    int countDistinct(vector<int> &nums, int k, int p) {
        int n = nums.size();
        this->k = k;
        for (int i = 0; i < n; i++) {
            if (nums[i] % p == 0) {
                idx[i] = true;
            } else {
                idx[i] = false;
            }
        }

        res = 0;
        vector<int> tmp;
        for (int i = 0; i < n; i++) {
            dfs(nums, tmp, 0, i);
        }

        return res;
    }
};
