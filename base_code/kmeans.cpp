#include <bits/stdc++.h>

using namespace std;

int latest_center(const vector<double> &dot, const vector<vector<double>> &center, const int dim) {
    double min_dist = INT_MAX;
    int idx = -1;
    for (int i = 0; i < center.size(); i++) {
        double dist = 0;
        for (int j = 0; j < dim; j++) {
            dist += (center[i][j] - dot[j]) * (center[i][j] - dot[j]);
        }
        if (dist < min_dist) {
            min_dist = dist;
            idx = i;
        }
    }
    return idx;
}

void Kmeans(const vector<vector<double>> &dots, const int k, const int dim, const int total_iter) {
    vector<vector<double>> center;
    for (int i = 0; i < k; i++) {
        center.push_back(dots[i]);
    }

    int n = dots.size();
    for (int iter = 0; iter < total_iter; iter++) {
        vector<vector<vector<double>>> dots_center(k);
        // 计算每个点所属类别
        for (int i = 0; i < n; i++) {
            int idx = latest_center(dots[i], center, dim);
            dots_center[idx].push_back(dots[i]);
        }

        // 更新中心点
        for (int i = 0; i < k; i++) { // 遍历中心
            vector<double> tmp(dim, 0);
            int m = dots_center[i].size();
            for (int j = 0; j < m; j++) {  // 遍历点
                for (int p = 0; p < dim; p++) {  // 遍历维度
                    tmp[p] += dots_center[i][j][p];
                }
            }
            for (int p = 0; p < dim; p++) {
                tmp[p] /= (double)m;
            }
            if (m > 0) {
                center[i] = tmp;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << latest_center(dots[i], center, dim) << " ";
    }
}

int main() {
    const vector<vector<double>> dots = {
            {1.5,   2.1},
            {0.8,   2.1},
            {1.3,   2.1},
            {110.5, 260.6},
            {21.7,  32.8},
            {130.9, 150.8},
            {32.6,  40.7},
            {41.5,  24.7}
    };
    const int k = 3;
    const int total_iter = 100;
    const int dim = dots[0].size();
    Kmeans(dots, k, dim, total_iter);
    return 0;
}