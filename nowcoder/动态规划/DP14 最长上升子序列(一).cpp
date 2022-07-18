#include<iostream>
#include<vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int>nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int res = 0;
    vector<int> dp(n, 1);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] < nums[j]) {
                dp[j] = max(dp[j], dp[i] + 1);
            }
        }
        res = max(dp[i], res);
    }

    cout << res << endl;
    return 0;
}