#include<iostream>
using namespace std;

int main(){
    float height = 0;
    cin >> height;
    float sum = 0;
    for (int i = 0; i < 5; i++) {
        if (i != 0) {
            sum += height * 2;
        } else {
            sum += height;
        }

        height /= 2;
    }

    cout << sum << endl;
    cout << height << endl;
}