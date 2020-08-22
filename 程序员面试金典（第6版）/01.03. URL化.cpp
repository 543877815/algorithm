// 时间复杂度：O(length)
// 空间复杂度：O(length+cnt*2)
class Solution {
public:
    string replaceSpaces(string S, int length) {
        if (S.empty()) return S;
        int cnt = 0;
        for (int i = 0; i < length; ++i) {
            if (S[i] == ' ') ++cnt;
        }
        int newLen = length + cnt * 2, j = newLen - 1;
        for (int i = length - 1; i >= 0 && i != j; --i) {
            if (S[i] == ' ') {
                S[j--] = '0';
                S[j--] = '2';
                S[j--] = '%';
            } else {
                S[j--] = S[i];
            }
        }
        S[newLen] = '\0';
        return S;
    }
};
