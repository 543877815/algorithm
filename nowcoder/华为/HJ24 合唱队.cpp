// 最长递增子序列
// 时间复杂度：O(n^2)
// 空间复杂度：O(n)
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> people(n, 0);
    int num;
    for (int i = 0; i < n; i++) {
        cin >> num;
        people[i] = num;
    }

    vector<int> left(n, 1);
    for (int i = 0; i < n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (people[i] > people[j]) {
                left[i] = max(left[i], left[j] + 1);
            }
        }
    }

    vector<int> right(n, 1);
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            if (people[i] > people[j]) {
                right[i] = max(right[i], right[j] + 1);
            }
        }
    }

    int res = 0;
    for (int i = 0; i < n; i++) {
        res = max(res, left[i] + right[i] - 1);
    }

    cout << n - res << endl;
}