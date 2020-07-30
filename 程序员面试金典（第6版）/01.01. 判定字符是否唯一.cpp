// 时间复杂度：O(n)
// 空间复杂度：O(n)

class Solution {
public:
    bool isUnique(string astr) {
        unordered_map<char, int> record;
        for(char i : astr) {
            if (record[i] == 1) return false;
            record[i] ++;
        }
        return true;
    }
};