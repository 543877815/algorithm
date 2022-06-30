// ��ϣ��
// ʱ�临�Ӷȣ�O(n)
// �ռ临�Ӷȣ�O(n)
#include<iostream>
#include<unordered_map>

using namespace std;

int main() {
    unordered_map<char, int> mymap;
    string str;
    getline(cin, str);
    for (int i = 0; i < str.size(); i++) {
        mymap[str[i]]++;
    }

    bool found = false;
    for (int i = 0; i < str.size(); i++) {
        if (mymap[str[i]] == 1) {
            found = true;
            cout << str[i];
            break;
        }
    }

    if (!found) cout << -1;

    return 0;
}