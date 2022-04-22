#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int a;
    cin >> a;
    string s;

    vector<string> ss;
    for (int i = 0; i < a; i++) {
        cin >> s;
        ss.push_back(s);
    }
    sort(ss.begin(), ss.end());

    for (int i = 0 ; i < a; i++) {
        cout << ss[i] << endl;
    }
}