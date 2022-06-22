#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr;

    int a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        arr.push_back(a);
    }

    int descend;
    cin >> descend;

    if (!descend) {
        sort(arr.begin(), arr.end(), less<int>());
    } else {
        sort(arr.begin(), arr.end(), greater<int>());
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}