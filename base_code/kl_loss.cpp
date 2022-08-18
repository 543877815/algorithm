#include "iostream"
#include "vector"
#include "cmath"

using namespace std;

float kl_loss(vector<double> &X, vector<double> &Y) {
    float res = 0;
    for (int i = 0; i < X.size(); i++) {
        res += X[i] * log(X[i] / Y[i]);
    }
    return res;
}

int main() {
    vector<double> X = {0.14285714, 0.04761905, 0.15873016, 0.07936508, 0.15873016, 0.06349206,
                        0.11111111, 0.0952381, 0.12698413, 0.01587302};
    vector<double> Y = {0.0952381, 0.07936508, 0.15873016, 0.01587302, 0.11111111, 0.14285714,
                        0.14285714, 0.0952381, 0.03174603, 0.12698413};
    cout << kl_loss(X, Y) << endl;
    cout << kl_loss(Y, X) << endl;
}