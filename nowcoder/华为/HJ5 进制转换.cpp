#include<iostream>

using namespace std;

int digitChange(string str) {
    int res = 0;
    for (int i = 2; i < str.size(); i++) {
        res = res * 16 + (str[i] >= 'A' ? (str[i] - 'A') + 10 : str[i] - '0');
    }

    return res;
}

int main() {
    string str;
    while (cin >> str) {
        cout << digitChange(str) << endl;
    }
}