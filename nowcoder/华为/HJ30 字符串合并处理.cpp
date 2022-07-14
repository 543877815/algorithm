// 哈希表
// 时间复杂度：O(nlogn)
// 空间复杂度：O(1)
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_map>
#include <math.h>
using namespace std;

int main(){
    string str_a, str_b;
    cin >> str_a >> str_b;
    string str = str_a + str_b;
    string tmp_a, tmp_b;
    int n = str.size();
    for (int i = 0; i < n; i++) {
        if (i % 2 == 1) {
            tmp_a += str[i];
        } else {
            tmp_b += str[i];
        }
    }
    sort(tmp_a.begin(), tmp_a.end());
    sort(tmp_b.begin(), tmp_b.end());
    int a = 0, b = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 1) {
            str[i] = tmp_a[a++];
        } else {
            str[i] = tmp_b[b++];
        }
    }

    unordered_map<char, char> hashmap;
    hashmap['0'] = '0';  hashmap['1'] = '8';  hashmap['2'] = '4';  hashmap['3'] = 'C';
    hashmap['4'] = '2';  hashmap['5'] = 'A';  hashmap['6'] = '6';  hashmap['7'] = 'E';
    hashmap['8'] = '1';  hashmap['9'] = '9';  hashmap['A'] = '5';  hashmap['B'] = 'D';
    hashmap['C'] = '3';  hashmap['D'] = 'B';  hashmap['E'] = '7';  hashmap['F'] = 'F';

    for (int i = 0; i < n; i++) {
        if (hashmap.count(toupper(str[i]))) {
            str[i] = hashmap[toupper(str[i])];
        }
    }

    cout << str;
}