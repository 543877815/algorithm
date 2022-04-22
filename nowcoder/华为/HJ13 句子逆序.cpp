#include<iostream>
#include<vector>

using namespace std;

int main() {
    string s;
    vector<string> ss;
    while(cin >> s) {
        ss.push_back(s);
    }
    for (int i = ss.size() - 1; i >= 0; i--) {
        cout << ss[i];
        if (i != 0) cout << " ";
    }
}