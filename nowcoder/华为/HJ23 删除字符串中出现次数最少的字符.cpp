// 哈希表
// 时间复杂度：O(n)
// 空间复杂度：O(n)
#include<iostream>
#include<string>
#include<unordered_map>
#include<climits>

using namespace std;

int main() {
    string str;
    cin >> str;
    unordered_map<char, int> count;
    for (int i = 0; i < str.size(); i++) {
        count[str[i]]++;
    }
    int min_count = INT_MAX;
    for (auto &[key, value]: count) {
        min_count = min(min_count, value);
    }

    string res;
    for (int i = 0; i < str.size(); i++) {
        if (count[str[i]] == min_count) continue;
        res.push_back(str[i]);
    }

    cout << res;
}