
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
#include<unordered_map>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<string> strs;
    string str;
    while (n > 0) {
        cin >> str;
        strs.push_back(str);
        n--;
    }
    int k;
    cin >> str >> k;
    vector<string> strs_set;
    vector<int> str_map(26, 0);
    for (int i = 0; i < str.size(); i++) {
        str_map[str[i] - 'a'] ++;
    }
    for (int i = 0; i < strs.size(); i++) {
        if (strs[i] == str || strs[i].size() != str.size()) continue;
        vector<int> tmp_map(26, 0);
        for (int j = 0; j < strs[i].size(); j++) {
            tmp_map[strs[i][j] - 'a']++;
        }

        bool valid = true;
        for (int j = 0; j < 26; j++) {
            if (str_map[j] != tmp_map[j]) {
                valid = false;
                break;
            }
        }
        if (valid) {
            strs_set.push_back(strs[i]);
        }
    }
    if (strs_set.empty()) {
        cout << 0;
        return 0;
    }
    sort(strs_set.begin(), strs_set.end());
    cout << strs_set.size() << endl << strs_set[k - 1];

}