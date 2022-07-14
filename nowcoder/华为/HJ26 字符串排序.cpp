#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
    string str;
    while (getline(cin, str)) {
        vector<char> v;
        for (int i = 0; i <= 25; i++) {  // ÅÅÐò
            for (int j = 0; j < str.size(); j++) {
                if (str[j] - 'a' == i || str[j] - 'A' == i) {
                    v.push_back(str[j]);
                }
            }
        }
        for (int i = 0, k = 0; i < str.size() && k < str.size(); i++) {
            if (isalpha(str[i])) {
                str[i] = v[k++];
            }
        }
        cout << str << endl;
    }
}