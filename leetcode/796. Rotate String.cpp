// 时间复杂度：O(n^2)
// 空间复杂度：O(n)
class Solution {
public:
    bool rotateString(string A, string B) {
        if (A.size() != B.size()) return false;
        string S = A + A;
        if (S.find(B) != S.npos) return true;
        else return false;
    }
};