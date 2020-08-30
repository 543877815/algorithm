// 时间复杂度：O(nm)
// 空间复杂度：O(nm)
class Solution {
public:
    vector <vector<int>> transpose(vector <vector<int>> &A) {
        int n = A.size();
        int m = A[0].size();
        vector <vector<int>> res;
        for (int i = 0; i < m; i++) {
            vector<int> tmp;
            for (int j = 0; j < n; j++) {
                tmp.push_back(A[j][i]);
            }
            res.push_back(tmp);
        }

        return res;
    }
};