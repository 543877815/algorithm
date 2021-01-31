// 贪心算法
// 时间复杂度：O(n^2)
// 空间复杂度：O(1)
class Solution {
public:
    int minSwapsCouples(vector<int> &row) {
        int n = row.size();
        int res = 0;
        for (int i = 0; i < n; i += 2) {
            int x = row[i];
            if (row[i + 1] == (x ^ 1)) continue;
            res++;
            for (int j = i + 1; j < n; j++) {
                if (row[j] == (x ^ 1)) {
                    int tmp = row[j];
                    row[j] = row[i + 1];
                    row[i + 1] = tmp;
                    break;
                }
            }
        }

        return res;
    }
};