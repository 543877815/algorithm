#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

int main(){
    string str_a, str_b;
    cin >> str_a >> str_b;
    int n = str_a.size(), m = str_b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for (int i = 0; i <= n; i++) {
        dp[i][0] = i;
    }
    for (int i = 0; i <= m; i++) {
        dp[0][i] = i;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (str_a[i-1] == str_b[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;
            }
        }
    }
    cout << dp[n][m];
    return 0;
}