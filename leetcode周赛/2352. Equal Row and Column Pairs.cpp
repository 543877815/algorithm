// 哈希表
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<string, int> rows;
        for (int i = 0; i < n; i++) {
            string tmp;
            for (int j = 0; j < n; j++) {
                tmp += to_string(grid[i][j]) + "#";
            }
            rows[tmp]++;
        }

        unordered_map<string, int> cols;
        for (int j = 0; j < n; j++) {
            string tmp;
            for (int i = 0; i < n; i++) {
                tmp += to_string(grid[i][j]) + "#";
            }
            cols[tmp]++;
        }


        int res = 0;
        for (auto &[key, val]: rows) {
            for (auto &[key2, val2]: cols) {
                if (key == key2) {
                    res += val * val2;
                }
            }
        }

        return res;
    }
};