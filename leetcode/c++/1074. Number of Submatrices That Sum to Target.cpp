// 暴力
// 时间复杂度：O(n^2m^2)
// 空间复杂度：O(nm)
class Solution {
public:
    int numSubmatrixSumTarget(vector <vector<int>> &matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector <vector<int>> prefixSum = vector < vector < int >> (n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                prefixSum[i][j] =
                        prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1] + matrix[i - 1][j - 1];
                // cout << prefixSum[i][j] << " ";
            }
            // cout << endl;
        }
        int res = 0;
        for (int startX = 0; startX < n; startX++) {
            for (int startY = 0; startY < m; startY++) {
                for (int endX = startX + 1; endX <= n; endX++) {
                    for (int endY = startY + 1; endY <= m; endY++) {
                        if (prefixSum[endX][endY] - prefixSum[endX][startY] - prefixSum[startX][endY] +
                            prefixSum[startX][startY] == target)
                            res++;
                    }
                }
            }
        }

        return res;
    }
};

// 用int暴力不超时
class Solution {
public:
    int numSubmatrixSumTarget(vector <vector<int>> &matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int s[m + 1][n + 1];
        memset(s, 0, sizeof s);

        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + matrix[i - 1][j - 1];

        int ans = 0;
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                for (int k = 1; k <= i; k++)
                    for (int l = 1; l <= j; l++) {
                        int sum = s[i][j] - s[i][l - 1] - s[k - 1][j] + s[k - 1][l - 1];
                        if (sum == target)
                            ans++;
                    }

        return ans;
    }
};

