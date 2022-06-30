// 暴力解法
// 时间复杂度：O(n^3)
// 空间复杂度：O(1)
#include<iostream>
#include<vector>

using namespace std;

int main() {
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);

    int maxLength = 0;
    string res;
    int n = str1.size(), m = str2.size();
    if (n > m) {
        swap(str1, str2);
        swap(n, m);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int k;
            for (k = 0; i + k < n && j + k < m; k++) {
                if (str1[i + k] != str2[j + k]) break;
            }
            if (k > maxLength) {
                maxLength = k;
                res = str1.substr(i, maxLength);
            }
        }
    }

    cout << res;

    return 0;
}

// 动态规划解法
// 时间复杂度：O(nm)
// 空间复杂度：O(nm)
#include<iostream>
#include<vector>

using namespace std;

int main() {
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);

    int maxLength = 0;
    string res;
    int n = str1.size(), m = str2.size();
    if (n > m) {
        swap(str1, str2);
        swap(n, m);
    }

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > maxLength) {
                    maxLength = dp[i][j];
                    res = str1.substr(i - maxLength, maxLength);
                }
            } else {
                dp[i][j] = 0;
            }
        }
    }

    cout << res;

    return 0;
}