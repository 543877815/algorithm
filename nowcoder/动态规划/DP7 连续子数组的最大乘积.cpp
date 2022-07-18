#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    int num;
    for (int i = 0; i < n; i++ ) {
        cin >> num;
        nums[i] = num;
    }

    int res = INT_MIN, imax = 1, imin = 1;
    for (int i = 0; i < n; i++) {
        if (nums[i] < 0) swap(imax, imin);
        imax = max(imax * nums[i], nums[i]);
        imin = min(imin * nums[i], nums[i]);

        res = max(res, imax);
    }

    cout << res;
}