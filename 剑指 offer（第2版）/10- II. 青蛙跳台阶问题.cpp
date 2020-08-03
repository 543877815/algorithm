long long F[200] = {0};

class Solution {
public:
    int numWays(int n) {
        F[0] = 1;
        F[1] = 1;
        F[2] = 2;
        for (int i = 3; i < 200; i++) {
            F[i] = (F[i - 1] + F[i - 2]) % 1000000007;
        }
        return F[n];
    }
};