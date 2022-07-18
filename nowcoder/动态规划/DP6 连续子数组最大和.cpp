#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int>nums (n, 0);
    int num;
    for (int i = 0; i < n; i++) {
        cin >> num;
        nums[i] = num;
    }

    int sum = 0;
    int res = INT_MIN;
    for (int i = 0; i < n; i++) {
        sum += nums[i];
        res = max(res, sum);
        if (sum < 0) sum = 0;
    }

    cout << res;
}