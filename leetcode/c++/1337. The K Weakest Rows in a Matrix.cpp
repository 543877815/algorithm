// 排序
// 时间复杂度：O(nm+nlogn)
// 空间复杂度：O(n+logn)
class Solution {
public:
    vector<int> kWeakestRows(vector <vector<int>> &mat, int k) {
        vector <pair<int, int>> record;
        int n = mat.size();
        int m = mat[0].size();
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 1) count++;
            }
            record.push_back(make_pair(count, i));
        }

        sort(record.begin(), record.end());
        vector<int> res;
        for (int i = 0; i < k; i++) {
            res.push_back(record[i].second);
        }

        return res;
    }
};