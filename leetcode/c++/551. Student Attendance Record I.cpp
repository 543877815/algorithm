// 一次遍历
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    bool checkRecord(string s) {
        int L_count = 0;
        int A_count = 0;
        bool L = true;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == 'L') L_count++;
            else L_count = 0;
            if (s[i] == 'A') A_count++;

            if (L_count >= 3) L = false;

        }

        return L && A_count < 2;
    }
};