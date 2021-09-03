// 遍历
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    bool isPalindrom(string &s, int left, int right) {
        while (left <= right) {
            if (s[left] != s[right]) return false;
            else {
                left++;
                right--;
            }
        }
        return true;
    }

    bool validPalindrome(string s) {
        int n = s.size();
        int left = 0, right = n - 1;
        int count = 0;
        while (left <= right) {
            if (s[left] == s[right]) {
                left++;
                right--;
            } else {
                if (!isPalindrom(s, left + 1, right) && !isPalindrom(s, left, right - 1)) return false;
                return true;
            }
        }
        return true;
    }
};