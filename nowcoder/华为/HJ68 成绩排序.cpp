#include <bits/stdc++.h>

using namespace std;


int main() {
    int n, isDe;
    cin >> n >> isDe;
    vector<pair<string, int>> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    if (isDe) {
        stable_sort(arr.begin(), arr.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
            return a.second < b.second;
        });
    } else {
        stable_sort(arr.begin(), arr.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
            return a.second > b.second;
        });
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i].first << " " << arr[i].second << endl;
    }
}