#include<iostream>

using namespace std;

int main() {
    int a;
    cin >> a;
    int res = 0;
    while(a != 0) {
        res += a % 2;
        a /= 2;
    }
    cout << res;
}