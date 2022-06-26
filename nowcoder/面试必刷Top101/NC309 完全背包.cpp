class Solution {
public:
    vector<int> knapsack(int v, int n, vector<vector<int> >& nums) {
        vector<int> a(v + 1, 0);
        vector<int> b(v + 1, INT_MIN);
        b[0] = 0;
        for (int i = 1; i <= n; i++) {
            int x = nums[i - 1][0];//最大容量
            int y = nums[i - 1][1];//最大价值
            for (int j = x; j <= v; j++) {
                a[j] = max(a[j], a[j - x] + y);
                b[j] = max(b[j], b[j - x] + y);
            }
        }
        return {a[v], b[v] > 0 ? b[v] : 0};
    }
};