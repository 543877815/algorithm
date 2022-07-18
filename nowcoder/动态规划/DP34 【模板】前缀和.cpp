#include<iostream>
#include<vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<long long> nums(n);
    long long num;
    for (int i = 0; i < n; i++) {
        cin >> num;
        nums[i] = num;
    }

    vector<long long> presum(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        presum[i] = presum[i-1] + nums[i-1];
    }

    for (int i = 0; i < m; i++) {
        int left, right;
        cin >> left >> right;
        cout << presum[right] - presum[left-1] << endl;
    }
}