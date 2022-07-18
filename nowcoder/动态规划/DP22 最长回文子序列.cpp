#include<iostream>
#include<vector>

using namespace std;

int main(){
    string str;
    cin >> str;
    int n = str.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }

    for (int i = n - 1; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            if (str[i] == str[j]) {
                dp[i][j] = dp[i+1][j-1] + 2;
            } else {
                dp[i][j] = max(dp[i+1][j], max(dp[i][j-1], dp[i+1][j-1]));
            }
        }

    }
    cout << dp[0][n-1];
    return 0;
}