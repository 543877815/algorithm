#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    while (cin >> n) {
        vector<int> nums(n);
        int num;
        for (int i = 0; i < n; i++) {
            cin >> num;
            nums[i] = num;
        }

        int k;
        cin >> k;
        cout << nums[n-k] << endl;
    }
}