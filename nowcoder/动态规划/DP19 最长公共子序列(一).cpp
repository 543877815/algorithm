#include<iostream>
#include<vector>

using namespace std;

int main() {
    int n, m;
    string str1, str2;
    cin >> n >> m >> str1 >> str2;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (str1[i-1] == str2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], max(dp[i-1][j-1], dp[i][j-1]));
            }
        }
    }

    cout << dp[n][m];
}