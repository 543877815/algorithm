// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    char firstUniqChar(string s) {
        unordered_map <char, int> record;
        for (int i = 0; i < s.size(); i++) {
            record[s[i]] ++;
        }
        for (int i = 0; i < s.size(); i++) {
            if (record[s[i]] == 1){
                return s[i];
            }
        }
        return ' ';
    }
};