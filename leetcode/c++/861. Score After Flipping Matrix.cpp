// 贪心算法
// 时间复杂度：O(mn)
// 空间复杂度：O(1)
class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int m = A.size();
        if (m == 0) return 0;
        int n = A[0].size();
        int res = m * (1 << (n - 1));
        for (int i = 1; i < n; i++) { // 列
            int one = 0;
            for (int j = 0; j < m; j++) { // 行
                if (A[j][0] == 1) one += A[j][i];
                else one += (1 - A[j][i]);  // 该行进行翻转
            }
            int k = max(one, m - one);
            res += k * (1 << (n - i - 1));
        }
        return res;
    }
};