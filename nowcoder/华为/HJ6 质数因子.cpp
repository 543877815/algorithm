#include<iostream>
#include<math.h>
#include<vector>

using namespace std;

int main() {
    long long a;
    cin >> a;
    int sqr_a = (int) sqrt(a);

    int n = sqr_a + 1;
    vector<bool> isFactor = vector<bool> (n, true);
    for (int i = 2; i < n; i++) {
        if (isFactor[i]) {
            for (int j = 2; i * j < n; j++) {
                isFactor[i * j] = false;
            }
        }
    }

    int num = 0;
    for (int i = 2; i < n; i++) {
        if (isFactor[i]) {
            while (!(a % i)) {
                a /= i;
                if (num != 0) cout << " ";
                cout << i;
                num++;
            }
        }
    }

    if (a != 1) {
        if (num != 0) cout << " ";
        cout << a;
    }


}