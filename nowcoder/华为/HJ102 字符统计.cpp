#include<bits/stdc++.h>
using namespace std;

int main() {
    string str;
    cin >> str;
    unordered_map<char, int> mymap;
    map<int, priority_queue<char, vector<char>, greater<int>>, greater<int>> freq2char;
    for (int i = 0; i < str.size(); i++) {
        mymap[str[i]]++;
    }

    for (auto &[key, value]: mymap) {
        freq2char[value].push(key);
    }

    string res;
    for (auto &[key, value]: freq2char) {
        while (!value.empty()) {
            res.push_back(value.top());
            value.pop();
        }
    }

    cout << res;
    return 0;

}