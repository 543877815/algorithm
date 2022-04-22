#include<iostream>
#include<map>

using namespace std;

int main () {
    int a;
    cin >> a;
    int b, c;
    map<int, int> myMap;
    while (cin >> b >> c) {
        if (myMap.find(b) == myMap.end()) {
            myMap[b] = c;
        } else {
            myMap[b] += c;
        }
    }

    for (auto&[key, value]: myMap) {
        cout << key << " " << value << endl;
    }

}