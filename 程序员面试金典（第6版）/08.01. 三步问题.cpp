// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    int waysToStep(int n) {
        vector<long long> F(n + 1, 0);
        for (int i = 0; i <= n; i++) {
            if (i == 0) F[0] = 1;
            else if (i == 1) F[1] = 1;
            else if (i == 2) F[2] = 2;
            else if (i == 3) F[3] = 4;
            else F[i] = (F[i - 1] + F[i - 2] + F[i - 3]) % 1000000007;
        }
        return F[n];
    }
};