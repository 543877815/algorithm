#include<iostream>
#include<cstring>

using namespace std;

int main() {
    double a;
    double sum = 0;
    int num_negative = 0;
    int num_positive = 0;

    while (cin >> a) {
        if (a >= 0) {
            num_positive++;
            sum += a;
        } else {
            num_negative++;
        }
    }

    cout << num_negative << endl;
    if (num_positive == 0) cout << "0.0" << endl;
    else printf("%.1lf", sum / num_positive);

    return 0;
}
}