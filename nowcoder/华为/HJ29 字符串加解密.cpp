// 时间复杂度：O(n)
// 空间复杂度：O(1)
#include <string>
#include <iostream>

using namespace std;

int main() {
    string str_a, str_b;
    cin >> str_a >> str_b;
    for (int i = 0; i < str_a.size(); i++) {
        if (isupper(str_a[i])) {
            str_a[i] = str_a[i] + 1 > 'Z' ? 'A' : str_a[i] + 1;
            str_a[i] = tolower(str_a[i]);
        } else if (islower(str_a[i])) {
            str_a[i] = str_a[i] + 1 > 'z' ? 'a' : str_a[i] + 1;
            str_a[i] = toupper(str_a[i]);
        } else if (isalnum(str_a[i])) {
            str_a[i] = str_a[i] + 1 > '9' ? '0' : str_a[i] + 1;
        }
    }
    cout << str_a << endl;
    for (int i = 0; i < str_b.size(); i++) {
        if (isupper(str_b[i])) {
            str_b[i] = str_b[i] - 1 < 'A' ? 'Z' : str_b[i] - 1;
            str_b[i] = tolower(str_b[i]);
        } else if (islower(str_b[i])) {
            str_b[i] = str_b[i] - 1 < 'a' ? 'z' : str_b[i] - 1;
            str_b[i] = toupper(str_b[i]);
        } else if (isalnum(str_b[i])) {
            str_b[i] = str_b[i] - 1 < '0' ? '9' : str_b[i] - 1;
        }
    }
    cout << str_b << endl;

}