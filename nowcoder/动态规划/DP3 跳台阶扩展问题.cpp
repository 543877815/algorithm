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

    vector<int> dp(n+1, 1);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            dp[i] += dp[j];
        }
    }

    cout << dp[n];
}