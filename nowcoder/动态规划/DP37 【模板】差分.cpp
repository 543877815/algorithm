#include<iostream>
#include<vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<long long> nums(n + 1);
    int num;
    for (int i = 1; i <= n; i++) {
        cin >> num;
        nums[i] = num;
    }

    int l, r, k;
    vector<long long> dp(n + 1, 0);
    for (int i = 0; i < m; i++) {
        cin >> l >> r >> k;
        dp[r + 1] -= k;
        dp[l] += k;
    }

    for (int i = 1; i <= n; i++) dp[i] += dp[i-1];
    for (int i = 1; i <= n; i++) cout << dp[i] + nums[i] << " ";
}