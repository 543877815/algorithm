#include<iostream>

using namespace std;

int main() {
    string str;
    cin >> str;
    int counter = 0;
    for (int i = 0; i < str.size(); i++) {
        cout << str[i];
        counter++;
        if (counter == 8) {
            counter = 0;
            cout << endl;
        }
    }

    if (counter != 0) {
        for (int i = counter; i < 8; i++) {
            cout << "0";
        }
    }

}