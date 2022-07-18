#include<iostream>
#include<vector>

using namespace std;

int main () {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    int num;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> num;
            matrix[i][j] = num;
        }
    }

    vector<vector<int>> dp(n, vector<int>(m, 0));
    dp[0][0] = matrix[0][0];
    for (int i = 1; i < n; i++) {
        dp[i][0] = dp[i-1][0] + matrix[i][0];
    }

    for (int j = 1; j < m; j++) {
        dp[0][j] = dp[0][j-1] + matrix[0][j];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            dp[i][j] = min(dp[i][j-1], dp[i-1][j]) + matrix[i][j];
        }
    }

    cout << dp[n-1][m-1];
}