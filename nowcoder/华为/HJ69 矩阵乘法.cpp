// 时间复杂度：O(nmp)
// 空间复杂度：O(np)
#include<iostream>
#include<vector>

using namespace std;

int main() {
    int n, m, p;
    cin >> n >> m >> p;
    vector<vector<int>> A(n, vector<int>(m, 0));
    vector<vector<int>> B(m, vector<int>(p, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
        }
    }

    for (int j = 0; j < m; j++) {
        for (int k = 0; k < p; k++) {
            cin >> B[j][k];
        }
    }

    vector<vector<int>> C(n, vector<int>(p, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            for (int k = 0; k < m; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }

            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}