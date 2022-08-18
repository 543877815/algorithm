#include "iostream"
#include "vector"
#include "math.h"

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


int main() {
    vector<float> A = {0, 0, 4, 4};
    vector<float> B = {2, 2, 3, 3};

    cout << iou(A, B);
}