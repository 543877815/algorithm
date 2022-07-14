// 最长回文子串
// 时间复杂度：O(n^2)
// 空间复杂度：O(1)
#include <string>
#include <iostream>

using namespace std;

int LongestSubPalindrome(string &str, int left, int right) {
    while (left >= 0 && right < str.size() && str[left] == str[right]) {
        left--;
        right++;
    }
    left++;
    right--;
    return right - left + 1;
}

int main() {
    string str;
    cin >> str;
    int n = str.size();
    int res = 0;
    for (int i = 0; i < n; i++) {
        res = max(res, LongestSubPalindrome(str, i, i));
        res = max(res, LongestSubPalindrome(str, i, i + 1));
    }

    cout << res;
}