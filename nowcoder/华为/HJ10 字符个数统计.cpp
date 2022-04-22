#include<iostream>
#include<vector>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    vector<bool> mymap(128, false);
    for (int i = 0; i < s.size(); i++) {
        if ((mymap[s[i] - ' '] ) == false) mymap[s[i] - ' '] = true;
    }

    int res = 0;
    for (int i = 0; i < 128; i++) {
        if (mymap[i]) res++;
    }

    cout << res;
}