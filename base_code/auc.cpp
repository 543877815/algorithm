#include <iostream>
#include <vector>

using namespace std;

float auc(vector<float> &labels, vector<float> &preds) {
    float res = 0;
    vector<int> pos;
    vector<int> neg;
    for (int i = 0; i < labels.size(); i++) {
        if (labels[i] == 1) pos.emplace_back(i);
        else neg.emplace_back(i);
    }

    for (int i: pos) {
        for (int j: neg) {
            if (preds[i] > preds[j]) res += 1;
            else if (preds[i] == preds[j]) res += 0.5;
        }
    }

    return res / (pos.size() * neg.size());
}

int main() {
    vector<float> labels = {1, 0, 0, 0, 1, 0, 1, 0};
    vector<float> preds = {0.9, 0.8, 0.3, 0.1, 0.4, 0.9, 0.66, 0.7};
    cout << auc(labels, preds);
}