// 时间复杂度：O(nm)
// 空间复杂度：O(nm)
class Solution {
public:
    vector <vector<int>> construct2DArray(vector<int> &original, int m, int n) {
        int k = original.size();
        vector <vector<int>> res;
        if (k != m * n) return res;
        int index = 0;
        for (int i = 0; i < m; i++) {
            vector<int> tmp(n);
            for (int j = 0; j < n; j++) {
                tmp[j] = original[index++];
            }
            res.push_back(tmp);
        }
        return res;
    }
};