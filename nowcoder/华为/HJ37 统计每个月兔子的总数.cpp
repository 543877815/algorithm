#include<iostream>
#include<vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    if (n <= 2) return 1;
    // dp表示能生育的兔子数
    vector<int> sum(n + 1, 0);
    sum[1] = sum[2] = 1;
    for (int i = 3; i <= n; i++) {
        sum[i] = sum[i - 1] + sum[i - 2];
    }

    cout << sum[n];

    return 0;
}