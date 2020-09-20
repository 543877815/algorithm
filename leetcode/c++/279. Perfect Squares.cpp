// 动态规划
// 时间复杂度：O(n)
// 空间复杂度：O(n)
int min(int a, int b){
    return a < b ? a : b;
}

int numSquares(int n){
    int *dp = (int *)malloc(sizeof(int) * (n+1));
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = i;
        for (int j = 1; i - j * j >= 0; j++) {
            dp[i] = min(dp[i], dp[i-j*j] + 1);
        }
    }
    return dp[n];
}


// 图建模，广度优先遍历
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    int numSquares(int n) {
        assert(n>0);
        queue<pair<int,int>> q;
        q.push(make_pair(n,0));
        vector<bool> visited(n+1, false);
        visited[n] = true;
        while(!q.empty()) {
            int num = q.front().first;
            int step = q.front().second;
            q.pop();
            for (int i = 1; num - i * i >= 0; i++) {
                int a = num - i * i;
                if (a < 0) break;
                if (a == 0) return step + 1;
                if (!visited[a]) {
                    q.push(make_pair(num-i*i, step+1));
                    visited[a] = true;
                }
            }
        }
        throw invalid_argument("No Solution.");
    }
};