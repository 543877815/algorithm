// ʱ�临�Ӷȣ�O(1)
// �ռ临�Ӷȣ�O(1)
#include<iostream>
#include<string.h>

using namespace std;

int main(){
    string str;
    int num;
    cin >> str;
    cin >> num;
    cout << str.substr(0, num);

    return 0;
}