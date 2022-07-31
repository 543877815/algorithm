// 哈希表
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    char repeatedCharacter(string s) {
        int n = s.size();
        unordered_map<char, int> mymap;
        for (int i = 0; i < n; i++) {
            mymap[s[i]]++;
            if (mymap[s[i]] == 2) return s[i];
        }
        return -1;
    }
};