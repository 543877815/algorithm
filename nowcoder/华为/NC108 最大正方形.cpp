// ǰ׺��˼·
// ʱ�临�Ӷȣ�O(nm*min(n,m))
// �ռ临�Ӷȣ�O(nm)
class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     * ���������
     * @param matrix char�ַ���vector<vector<>>
     * @return int����
     */
    int solve(vector <vector<char>> &matrix) {
        // write code here
        int n = matrix.size();
        if (n == 0) return 0;
        int m = matrix[0].size();
        vector <vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + (matrix[i - 1][j - 1] - '0');
            }
        }

        int res = 0;
        for (int i = n; i > 0; i--) {
            for (int j = m; j > 0; j--) {
                for (int k = min(n, m); k >= 1; k--) {
                    if (i - k >= 0 && j - k >= 0) {
                        if (dp[i][j] - dp[i - k][j] - dp[i][j - k] + dp[i - k][j - k] == k * k) {
                            res = max(res, k * k);
                        }
                    }
                }
            }
        }

        return res;
    }
};


// ��̬�滮
// ʱ�临�Ӷȣ�O(nm)
// �ռ临�ӵģ�O(nm)
class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     * ���������
     * @param matrix char�ַ���vector<vector<>>
     * @return int����
     */
    int solve(vector <vector<char>> &matrix) {
        // write code here
        int n = matrix.size();
        if (n == 0) return 0;
        int m = matrix[0].size();
        vector <vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        int res = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (matrix[i - 1][j - 1] == '1') {
                    dp[i][j] = min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1])) + 1;
                    res = max(res, dp[i][j]);
                }
            }
        }

        return res * res;
    }
};