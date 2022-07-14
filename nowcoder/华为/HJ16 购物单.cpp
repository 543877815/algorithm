// 动态规划
// 时间复杂度：O(nm)
// 空间复杂度：O(nm)
#include<iostream>
#include<math.h>
#include<vector>

using namespace std;

int main() {
    int N, m;
    while (cin >> N >> m) {
        vector<vector<int>> vs(m + 1, vector<int>(3, 0));
        vector<vector<int>> weight(m + 1, vector<int>(3, 0));
        int v, p, q;
        for (int i = 1; i <= m; i++) {
            cin >> v >> p >> q;
            if (q) {  // 表示为附件
                if (!vs[q][1]) { // 表示第一件附件
                    vs[q][1] = v;
                    weight[q][1] = v * p;
                } else { // 表示第二件附件
                    vs[q][2] = v;
                    weight[q][2] = v * p;
                }
            } else { // 表示为主件
                vs[i][0] = v;
                weight[i][0] = v * p;
            }
        }

        int n = N / 10; // 每个物品的价格都是10的整数倍
        vector<int> total_max(n + 1);
        for (int i = 1; i <= m; i++) {
            for (int j = n; j >= vs[i][0] / 10; j--) {
                int value_total, weight_total;

                value_total = vs[i][0] / 10;
                weight_total = weight[i][0];
                total_max[j] = max(total_max[j], total_max[j - value_total] + weight_total); // 不带附件

                value_total = vs[i][0] / 10 + vs[i][1] / 10; // 带第一个附件
                weight_total = weight[i][0] + weight[i][1];
                if (value_total <= j && vs[i][1]) {
                    total_max[j] = max(total_max[j], total_max[j - value_total] + weight_total);
                }

                value_total = vs[i][0] / 10 + vs[i][2] / 10; // 带第二个附件
                weight_total = weight[i][0] + weight[i][2];
                if (value_total <= j && vs[i][2]) {
                    total_max[j] = max(total_max[j], total_max[j - value_total] + weight_total);
                }

                value_total = vs[i][0] / 10 + vs[i][1] / 10 + vs[i][2] / 10; // 带第一和第二个附件
                weight_total = weight[i][0] + weight[i][1] + weight[i][2];
                if (value_total <= j && vs[i][1] && vs[i][2]) {
                    total_max[j] = max(total_max[j], total_max[j - value_total] + weight_total);
                }
            }
        }
        cout << total_max[n] << endl;
        return 0;
    }
}