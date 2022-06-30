// 动态规划
// 时间复杂度：O(nm)
// 空间复杂度：O(nm)
#include<iostream>
#include<vector>
#include <ctype.h>

using namespace std;

bool isLegal(char a) {
    return isalpha(a) || isalnum(a);
}

int main() {
    string str1, str2;
    cin >> str1 >> str2;

    int n = str1.size(), m = str2.size();
    vector<vector<bool>>dp(n + 1, vector<bool>(m + 1, false));
    for (int i = 0; i < n; i++) {
        if (str1[i] >= 'A' && str1[i] <= 'Z') {
            str1[i] = str1[i] - 'A' + 'a';
        }
    }

    for (int j = 0; j < m; j++) {
        if (str2[j] >= 'A' && str2[j] <= 'Z') {
            str2[j] = str2[j] - 'A' + 'a';
        }
    }

    for (int i = 1; i <= n; i++) {
        if (str1[i-1] == '*') dp[i][0] = true;
        else break;
    }

    dp[0][0] = true;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (str1[i-1] == '*' && isLegal(str2[j-1])) {
                dp[i][j] = dp[i][j-1] | dp[i-1][j] | dp[i-1][j-1];
            } else {
                if (str1[i-1] == str2[j-1] || str1[i-1] == '?') {
                    dp[i][j] = dp[i-1][j-1];
                }
            }

        }
    }
    cout << (dp[n][m] == 0 ? "false" : "true");
    return 0;
}