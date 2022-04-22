#include<iostream>
using namespace std;

int main() {
    string str;
    while (cin >> str) {
        if (cin.get() == '\n') {
            cout << str.size() << endl;
        }
    }
}