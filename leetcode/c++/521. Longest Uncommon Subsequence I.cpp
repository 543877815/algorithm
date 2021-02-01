// 时间复杂度：O(1)
// 空间复杂度：O(1)
class Solution {
public:
    int findLUSlength(string a, string b) {
        if (a == b) return -1;
        else return max(a.size(), b.size());
    }
};