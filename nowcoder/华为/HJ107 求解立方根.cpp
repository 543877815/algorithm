
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

float abs_f(float x) {
    return x > 0 ? x : -x;
}

int main() {

    float a;
    while (cin >> a) {
        float res = 0;
        float dis = 20;
        bool negative = false;
        if (a < 0) negative = true;
        a = abs(a);
        for (float i = 1; i <= 28; i++) {
            float b = i / 10;
            float tmp = abs_f(b * b * b - a);
            if (tmp < dis) {
                dis = tmp;
                res = b;
            }
        }
        cout << (negative ? -res : res) << endl;
    }

    return 0;
}