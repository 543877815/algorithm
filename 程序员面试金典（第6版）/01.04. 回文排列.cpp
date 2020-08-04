// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> record;
        for (int i = 0; i < s.size(); i++) {
            record[s[i]]++;
        }
        int count = 0;
        for (auto chara : record) {
            if (chara.second % 2) {
                count++;
            }
            if (count == 2) return false;
        }

        return true;
    }
};