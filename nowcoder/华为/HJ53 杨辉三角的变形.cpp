#include<iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    if (n == 2 || n == 1) {
        cout << -1 << endl;
        return 0;
    }
    if (n % 2 == 1) {
        cout << 2 << endl;
        return 0;
    }
    if (n / 2 % 2 == 1) {
        cout << 4 << endl;
    } else {
        cout << 3 << endl;
    }
}