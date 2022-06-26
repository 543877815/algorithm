// 栈
// 时间复杂度：O(n)
// 空间复杂度：O(n)
#include<iostream>
#include<string.h>
#include<stack>
#include<sstream>

using namespace std;

int main() {
    stack<string> sk;
    string str;
    while (cin >> str) {
        string tmp;
        for (int i = 0; i < str.size(); i++) {
            if ((str[i] <= 'z' && str[i] >= 'a') || str[i] <= 'Z' && str[i] >= 'A') {
                tmp += str[i];
            } else if (tmp.size() != 0) {
                sk.push(tmp);
                tmp = "";
            }
        }
        if (tmp.size() != 0) sk.push(tmp);
    }

    while (!sk.empty()) {
        cout << sk.top() << " ";
        sk.pop();
    }

    return 0;
}