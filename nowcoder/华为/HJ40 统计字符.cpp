#include<iostream>
#include<cstring>

using namespace std;

int main() {

    string str;
    getline(cin, str);
    int n = str.size();
    int letter = 0, space = 0, num = 0, other = 0;
    for (int i = 0; i < n; i++) {
        if (str[i] == ' ') space++;
        else if (isdigit(str[i])) num++;
        else if (isupper(str[i]) || islower(str[i])) letter++;
        else other++;
    }

    cout << letter << endl;
    cout << space << endl;
    cout << num << endl;
    cout << other << endl;

    return 0;
}