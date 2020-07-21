class Solution {
public:
    int fib(int N) {
        if (N==0) return 0;
        if (N==1) return 1;
        return fib(N-1) + fib(N-2);
    }
};

class Solution {
public:
    int fib(int N) {
        if (N==0 || N == 1) return N;
        int a = 1, b = 0;
        for (int i = 1; i < N; i++) {
            a = a + b;
            b = a - b;
            a %= 1000000007;
        }
        return a;
    }
};