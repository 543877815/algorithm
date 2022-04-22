#include<iostream>
using namespace std;

int main() {
    double a;
    while(cin >> a){
        cout << static_cast<int>(a + 0.5) << endl;
    }
}