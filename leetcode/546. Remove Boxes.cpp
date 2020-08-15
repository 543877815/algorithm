// 时间复杂度：O(n^4)
// 空间复杂度：O(n^3)
class Solution {
public:
    // dp[i][j][k] 表示从移除区间[i, j]加上该区间右边等于a_r的k个元素组成的最大积分
    // dp[i][j][k] = max(f[i,j-1,0] + (k+1)^2, max(f(i,j,k+1)+f(i+1,r-1,0)))
    int dp[100][100][100];

    int removeBoxes(vector<int> &boxes) {
        memset(dp, 0, sizeof dp);   // 初始化为0
        return calculatePoints(boxes, 0, boxes.size() - 1, 0);
    }

    int calculatePoints(vector<int> &boxes, int l, int r, int k) {
        if (l > r) return 0;
        if (dp[l][r][k] != 0) return dp[l][r][k];
        while (r > l && boxes[r] == boxes[r - 1]) {
            r--;
            k++;
        }
        dp[l][r][k] = calculatePoints(boxes, l, r - 1, 0) + (k + 1) * (k + 1);
        for (int i = l; i < r; i++) {
            if (boxes[i] == boxes[r]) {
                dp[l][r][k] = max(dp[l][r][k],
                                  calculatePoints(boxes, l, i, k + 1) + calculatePoints(boxes, i + 1, r - 1, 0));
            }
        }
        return dp[l][r][k];
    }
};