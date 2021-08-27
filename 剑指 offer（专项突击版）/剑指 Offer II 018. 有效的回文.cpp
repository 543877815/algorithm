// 双指针
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;
        while (left < right) {
            while (left < right && !isalnum(s[left])) left++;
            while (left < right && !isalnum(s[right])) right--;
            if (left < right) {
                if (tolower(s[left]) != tolower(s[right])) return false;
                left++;
                right--;
            }
        }
        return true;
    }
};