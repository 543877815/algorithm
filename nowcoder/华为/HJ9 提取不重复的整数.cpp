#include<iostream>
#include<vector>

using namespace std;

int main () {
    long long a;
    cin >> a;
    vector<bool> myMap (10, false);
    while (a != 0) {
        int num = a % 10;
        if (myMap[num] == false) {
            myMap[num] = true;
            cout << num;
        }
        a /= 10;
    }
}