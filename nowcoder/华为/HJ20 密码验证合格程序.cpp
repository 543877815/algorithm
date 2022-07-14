// 时间复杂度：O(nm)
// 空间复杂度：O(n)
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string str;
    while (cin >> str) {
        bool hasDigit = false;
        bool hasUpper = false;
        bool hasLower = false;
        bool hasOther = false;
        int n = str.size();
        if (n < 8) {
            cout << "NG" << endl;
            continue;
        }
        for (int i = 0; i < n; i++) {
            if (isdigit(str[i])) hasDigit = true;
            else if (str[i] <= 'Z' && str[i] >= 'A') hasUpper = true;
            else if (str[i] <= 'z' && str[i] >= 'a') hasLower = true;
            else if (str[i] != '\n' && str[i] != ' ') hasOther = true;
        }
        if (hasDigit + hasLower + hasUpper + hasOther < 3) {
            cout << "NG" << endl;
            continue;
        }
        bool valid = true;
        for (int i = 0; i <= n - 6; i++) {
            for (int j = i + 3; j < n; j++) {
                if (str[i] == str[j] && str[i + 1] == str[j + 1] && str[i + 2] == str[j + 2]) {
                    cout << "NG" << endl;
                    valid = false;
                    break;
                }
            }
            if (!valid) break;
        }
        if (valid) cout << "OK" << endl;
    }
    return 0;
}