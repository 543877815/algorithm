// 时间复杂度：O(n)
// 空间复杂度：O(n)
#include<iostream>
#include<vector>

using namespace std;

int main() {
    int num;
    cin >> num;

    vector<bool> isPrime(num + 1, true);

    for (int i = 2; i <= num; i++) {
        for (int j = 2; i * j <= num; j++) {
            isPrime[i * j] = false;
        }
    }
    int mid = num / 2;
    int left = mid, right = mid;
    while (left >= 0 && !isPrime[left]) left--;
    while (right <= num && !isPrime[right]) right++;

    while (left >= 0 && right <= num && left + right != num) {
        if (left + right > num) {
            do { left--; } while (left >= 0 && !isPrime[left]);
        } else {
            do { right++; } while (right <= num && !isPrime[right]);
        }
    }

    cout << left << endl << right;
    return 0;
}