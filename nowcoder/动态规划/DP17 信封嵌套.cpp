// 时间复杂度：O(n^2)
// 空间复杂度：O(n)
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> nums(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        cin >> nums[i][0] >> nums[i][1];
    }

    sort(nums.begin(), nums.end(), [&](vector<int> &a, vector<int> &b) {
        if (a[0] != b[0]) return a[0] < b[0];
        else return a[1] < b[1];
    });
    int res = 0;
    vector<int> dp(n, 1);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i][0] < nums[j][0] && nums[i][1] < nums[j][1]) {
                dp[j] = max(dp[j], dp[i] + 1);
            }
        }
        res = max(res, dp[i]);
    }

    cout << res;
}