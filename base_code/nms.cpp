#include "iostream"
#include "vector"
#include "cmath"
#include "algorithm"
#include "numeric"

using namespace std;

float max(float a, float b) {
    return a > b ? a : b;
}

float iou(const vector<float> &A, const vector<float> &B) {
    float xmin1 = A[0], ymin1 = A[1], xmax1 = A[2], ymax1 = A[3];
    float xmin2 = B[0], ymin2 = B[1], xmax2 = B[2], ymax2 = B[3];
    float area1 = (xmax1 - xmin1) * (ymax1 - ymin1);
    float area2 = (xmax2 - xmin2) * (ymax2 - ymin2);

    float xmin = max(xmin1, xmin2);
    float ymin = max(ymin1, ymin2);
    float xmax = min(xmax1, xmax2);
    float ymax = min(ymax1, ymax2);
    float inter_area = max(0, (xmax - xmin)) * max(0, (ymax - ymin));

    float iou_res = inter_area / (area1 + area2 - inter_area);
    return iou_res;
}


vector<int> nms(const vector<vector<float>> &preds, const vector<float> &scores, float threhold = 0.5) {
    int n = preds.size();
    vector<int> id(n, 0);
    iota(id.begin(), id.end(), 0);
    sort(id.begin(), id.end(), [&](int i, int j) {
        return scores[i] > scores[j];
    });
    vector<int> res;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++) {
        if (visited[id[i]]) continue;
        visited[id[i]] = true;
        res.push_back(id[i]);
        for (int j = i + 1; j < n; j++) {
            if (iou(preds[id[i]], preds[id[j]]) > 0.5) {
                visited[id[j]] = true;
            }
        }
    }
    return res;
}


int main() {
    vector<vector<float>> A = {
            {0, 0, 4, 4},
            {1, 1, 5, 5},
            {2, 2, 3, 3},
            {4, 4, 8, 8},
            {3, 3, 8, 8}
    };
    vector<float> B = {0.9, 0.8, 0.7, 0.6, 0.8};

    vector<int> idx = nms(A, B);
    for (int i = 0; i < idx.size(); i++) {
        cout << idx[i] << endl;
    }
}