#include<iostream>
#include<vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    int num;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> num;
        nums[i] = num;
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (sum < i) break;
        sum = max(sum, i + nums[i]);
    }
    if (sum >= n - 1) cout << "true";
    else cout << "false";
}