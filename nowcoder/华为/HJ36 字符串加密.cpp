#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<char, char>hashmap;
    unordered_map<char, char>mapping;
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);
    int idx = 0;
    for (int i = 0; i < str1.size(); i++) {
        if (!hashmap.count(str1[i])) {
            hashmap[tolower(str1[i])] = 'a' + idx;
            hashmap[toupper(str1[i])] = 'A' + idx;
            mapping['A' + idx] = toupper(str1[i]);
            mapping['a' + idx] = tolower(str1[i]);
            idx++;
        }
    }

    for (int i = 0; i < 26; i++) {
        if (!hashmap.count('a' + i)) {
            hashmap['a' + i] = 'a' + idx;
            hashmap['A' + i] = 'A' + idx;

            mapping['A' + idx] = 'A' + i;
            mapping['a' + idx] = 'a' + i;
            idx++;
        }

    }

    for (int i = 0; i < str2.size(); i++) {
        if (hashmap.count(str2[i])) cout << mapping[str2[i]];
        else cout << str2[i];
    }

}