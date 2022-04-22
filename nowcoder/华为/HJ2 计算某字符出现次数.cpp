#include<iostream>

using namespace std;

int main() {
    string str;
    getline(cin, str);
    char c;
    cin >> c;

    if (c >= 'A' && c <= 'Z') {
        c = c - 'A' + 'a';
    }

    int res = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] - 'A' + 'a';
        }

        if (str[i] == c) res++;
    }

    cout << res << endl;
}