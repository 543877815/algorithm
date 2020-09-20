// 时间复杂度：O(n)
// 空间复杂度：O(s) s为字符集大小
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> hash;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            hash[s[i]]++;
        }
        int hasEven = false;
        int res = 0;
        for (auto iter : hash) {
            // 如果是偶数
            if ((iter.second & 1) == 0) {
                res += iter.second;
            } else { // 如果是奇数
                res += iter.second - 1;
                hasEven = true;
            }
        }
        res += hasEven;
        return res;
    }
};