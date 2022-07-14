// 模拟
// 时间复杂度：O(n)
// 空间复杂度：O(1)
#include<iostream>

using namespace std;

int main() {
    int n; // 空瓶子数量
    while (cin >> n) {
        if (n == 0) return 0;
        int res = 0;
        int curr = n / 3; // 可以换的可乐
        n = n % 3; // 剩下的瓶子数量
        res += curr;
        while (curr > 0) {
            n += curr;
            curr = n / 3;
            n = n % 3;
            res += curr;
        }

        if (n == 2) res++;
        cout << res << endl;
    }
    return 0;
}