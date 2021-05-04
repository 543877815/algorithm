// 栈
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
    int clumsy(int N) {
        stack<int> sk;
        sk.push(N);
        int opera = 0; // 0 : *, 1 : /, 2 : +, 3 : -
        for (int i = N - 1; i > 0; i--) {
            if (opera == 0) {
                int top = sk.top();
                sk.pop();
                sk.push(top * i);
            } else if (opera == 1) {
                int top = sk.top();
                sk.pop();
                sk.push(top / i);
            } else if (opera == 2) {
                sk.push(i);
            } else if (opera == 3) {
                sk.push(-i);
            }
            opera++;
            if (opera == 4) opera = 0;
        }

        int res = 0;

        while (!sk.empty()) {
            res += sk.top();
            sk.pop();
        }

        return res;
    }
};


class Solution {
public:
    int clumsy(int N) {
        if (N == 1) return 1;
        else if (N == 2) return 2;
        else if (N == 3) return 6;
        else if (N == 4) return 7;

        if (N % 4 == 0) return N + 1;
        else if (N % 4 <= 2) return N + 2;
        else return N - 1;
    }
};