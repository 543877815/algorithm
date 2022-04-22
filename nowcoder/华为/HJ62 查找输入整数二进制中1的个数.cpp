#include<iostream>

using namespace std;

int main() {
    long long a;
    while(cin >> a) {
        int res = 0;
        while(a != 0) {
            res += a % 2;
            a /= 2;
        }
        cout << res << endl;
    }
}