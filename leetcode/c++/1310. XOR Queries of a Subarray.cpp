// 前缀和
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    vector<int> xorQueries(vector<int> &arr, vector <vector<int>> &queries) {
        int n = queries.size();
        vector<int> res;
        if (n == 0) return res;

        int m = arr.size();
        vector<int> prefix;
        int tmp = 0;
        for (int i = 0; i < m; i++) {
            tmp ^= arr[i];
            prefix.push_back(tmp);
        }

        for (int i = 0; i < n; i++) {
            int start = queries[i][0], end = queries[i][1];
            if (start > 0) res.push_back(prefix[start - 1] ^ prefix[end]);
            else res.push_back(prefix[end]);
        }
        return res;
    }
};