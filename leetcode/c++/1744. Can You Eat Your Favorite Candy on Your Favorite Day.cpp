// 空间复杂度：O(n)
// 时间复杂度：O(n+m)
class Solution {
public:
    vector<bool> canEat(vector<int> &candiesCount, vector <vector<int>> &queries) {
        int n = candiesCount.size();
        int m = queries.size();
        vector<bool> res(m, false);
        vector<long long> latest(n, 0);  // 每天只吃一个糖到达该类型糖的天数，上界
        for (int i = 0; i < n; i++) {
            if (i == 0) latest[i] = candiesCount[i] - 1;
            else latest[i] = latest[i - 1] + candiesCount[i];
        }
        cout << endl;
        for (int i = 0; i < m; i++) {
            int favoriteType = queries[i][0];
            int favoriteDay = queries[i][1];
            int dailyCap = queries[i][2];
            long long earliest = (favoriteType == 0 ? 0 : (latest[favoriteType - 1] + 1) / dailyCap);
            if (earliest <= favoriteDay && favoriteDay <= latest[favoriteType]) {
                res[i] = true;
            }
        }
        return res;
    }
};