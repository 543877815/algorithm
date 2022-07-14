// 哈希表
// 时间复杂度：O(n)
// 空间复杂度：O(1)
#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

int main() {
    string str;
    unordered_map<char, char> mapping;
    mapping['1'] = '1';
    mapping['a'] = mapping['b'] = mapping['c'] = '2';
    mapping['d'] = mapping['e'] = mapping['f'] = '3';
    mapping['g'] = mapping['h'] = mapping['i'] = '4';
    mapping['j'] = mapping['k'] = mapping['l'] = '5';
    mapping['m'] = mapping['n'] = mapping['o'] = '6';
    mapping['p'] = mapping['q'] = mapping['r'] = mapping['s'] = '7';
    mapping['t'] = mapping['u'] = mapping['v'] = '8';
    mapping['w'] = mapping['x'] = mapping['y'] = mapping['z'] = '9';
    mapping['0'] = '0';
    while (cin >> str) {
        int n = str.size();
        for (int i = 0; i < n; i++) {
            if (islower(str[i])) {
                str[i] = mapping[str[i]];
            } else if (isupper(str[i])) {
                str[i] = tolower(str[i]) + 1;
                if (str[i] > 'z') str[i] = 'a';
            }
        }
        cout << str << endl;
    }

    return 0;
}