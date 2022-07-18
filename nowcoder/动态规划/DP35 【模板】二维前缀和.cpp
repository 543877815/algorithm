#include<iostream>
#include<vector>

using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<long long>> matrix(n, vector<long long>(m));
    int num;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> num;
            matrix[i][j] = num;
        }
    }

    vector<vector<long long>> presum(n+1, vector<long long>(m+1, 0));
    for (int i = 1; i <= n; i++ ){
        for (int j = 1; j <= m; j++) {
            presum[i][j] = presum[i-1][j] + presum[i][j-1] - presum[i-1][j-1] + matrix[i-1][j-1];
        }
    }

    for (int i = 0; i < q; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--; y1--;
        cout << presum[x2][y2] - presum[x1][y2] - presum[x2][y1] + presum[x1][y1] << endl;
    }
}