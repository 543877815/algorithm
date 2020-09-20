// 时间复杂度: O(n)
// 空间复杂度: O(1)
class Solution {
public:
    string reverseVowels(string s) {
        string str = "aeiou";
        int left = 0;
        int right = s.size() - 1;
        while(left < right) {
            while(left < right && str.find(tolower(s[left]))==-1) {
                left ++;
            }
            while(left < right && str.find(tolower(s[right]))==-1) {
                right --;
            }
            swap(s[left], s[right]);
            left++;
            right--;
        }
        return s;
    }
};