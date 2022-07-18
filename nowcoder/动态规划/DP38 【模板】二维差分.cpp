#include<iostream>
#include<vector>

using namespace std;

int main (){
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<long long>> nums(n+1, vector<long long>(m+1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> nums[i][j];
        }
    }

    vector<vector<long long>> dp(n+2, vector<long long>(m+2, 0));
    for (int i = 0; i < q; i++) {
        int x1, y1, x2, y2, k;
        cin >> x1 >> y1 >> x2 >> y2 >> k;
        dp[x1][y1] += k;
        dp[x1][y2+1] -= k;
        dp[x2+1][y1] -= k;
        dp[x2+1][y2+1] += k;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] += dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << dp[i][j] + nums[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}