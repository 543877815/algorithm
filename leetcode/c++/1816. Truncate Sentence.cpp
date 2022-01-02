// 遍历一次
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    string truncateSentence(string s, int k) {
        int n = s.size();
        int i = 0;
        while (k != 0 && i < n) {
            if (s[i] == ' ') k--;
            i++;
        }
        if (i == n)
            return s.substr(0, i);
        else return s.substr(0, i - 1);
    }
};