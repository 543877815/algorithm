// 计数
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int n = dominoes.size();
        int res = 0;
        if (n == 0) return res;
        int record[10][10] = {0};
        for (int i = 0; i < n; i++) {
            int x = dominoes[i][0], y = dominoes[i][1];
            record[x][y]++;
        }
        int sum;
        for (int i = 1; i < 10; i++) {
            for (int j = i; j < 10; j++) {
                if (i != j) sum = record[i][j] + record[j][i];
                else sum = record[i][j];
                res += sum * (sum - 1) / 2;
            }
        }
        return res;
    }
};