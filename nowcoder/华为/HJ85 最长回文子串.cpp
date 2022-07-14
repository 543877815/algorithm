// 时间复杂度：O(n^2)
// 空间复杂度：O(1)
#include<iostream>
#include<string>

using namespace std;

int getLength(string& str, int left, int right) {
    int n = str.size();
    while (str[left] == str[right] && left >= 0 && right < n) {
        left--;
        right++;
    }
    left++; right--;
    return right-left+1;
}

int main(){
    string str;
    cin >> str;
    int n = str.size();
    int res = 0;
    for (int i = 0; i < n; i++) {
        res = max(res, getLength(str, i, i));
        res = max(res, getLength(str, i, i+1));
    }

    cout << res << endl;
}