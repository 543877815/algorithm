#include<iostream>
#include<vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    if (n == 1 || n == 2) {
        cout << 1;
        return 0;
    }

    vector<int> dp(n + 1, 1);
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    cout << dp[n];

    return 0;
}