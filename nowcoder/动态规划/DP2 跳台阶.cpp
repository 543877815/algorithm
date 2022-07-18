#include<iostream>
#include<vector>

using namespace std;

int main (){
    int n;
    cin >> n;
    if (n <= 2) {
        cout << n;
        return 0;
    }

    vector<int> dp(n+1, 0);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    cout << dp[n];
}